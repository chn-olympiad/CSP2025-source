#include<bits/stdc++.h>
using namespace std;

const int N=100015;
int t,n,s;
int a[N][5];
pair<int,int>k[N];
int j[5];

void init(){
	for(int i=0;i<5;i++)j[i]=0;
	for(int i=0;i<=n+5;i++)
		k[i].first=k[i].second=a[i][0]=a[i][1]=a[i][2]=a[i][3]=a[i][4]=0;
	s=n=0;
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	for(int i=1;i<=n;i++){
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			k[i].first=min(abs(a[i][1]-a[i][2]),abs(a[i][1]-a[i][3])),
			a[i][0]=1,j[1]++;
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			k[i].first=min(abs(a[i][2]-a[i][1]),abs(a[i][2]-a[i][3])),
			a[i][0]=2,j[2]++;
		else
			k[i].first=min(abs(a[i][3]-a[i][1]),abs(a[i][3]-a[i][2])),
			a[i][0]=3,j[3]++;
		k[i].second=i;
	}
	sort(k+1,k+n+1);
	if(j[1]>n/2){
		int l=j[1]-n/2;
		for(int i=1;l>0&&i<=n;i++)
			if(a[k[i].second][0]==1)
				a[k[i].second][0]=(a[i][2]>a[i][3]?2:3),l--;
	}else if(j[2]>n/2){
		int l=j[2]-n/2;
		for(int i=1;l>0&&i<=n;i++)
			if(a[k[i].second][0]==2)
				a[k[i].second][0]=(a[i][1]>a[i][3]?1:3),l--;
	}else if(j[3]>n/2){
		int l=j[3]-n/2;
		for(int i=1;l>0&&i<=n;i++)
			if(a[k[i].second][0]==3)
				a[k[i].second][0]=(a[i][1]>a[i][2]?1:2),l--;
	}
	for(int i=1;i<=n;i++)s+=a[i][a[i][0]];
	cout<<s<<"\n";
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		init();
		solve();
	}
	return 0;
}

