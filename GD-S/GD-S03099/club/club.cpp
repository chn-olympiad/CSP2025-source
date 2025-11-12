#include<bits/stdc++.h>
using namespace std;
int a[100007],b[100007],c[100007];

struct as{
	int first;
	int second;
	int cc;
};
as x[100007];
bool cmp(as a,as b){
	return a.first-a.second<b.first-b.second;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t;cin>>t;
while(t--){
unsigned long long ans=0;
	int n;cin>>n;
	int m=0,k=0,l=0;
	for(int j=1;j<=n;j++){
		cin>>a[j]>>b[j]>>c[j];
		x[j].first=max(a[j],b[j]);
		x[j].first=max(x[j].first,c[j]);
		if(x[j].first==c[j])x[j].second=max(a[j],b[j]);
		else if(x[j].first==a[j])x[j].second=max(b[j],c[j]);
		else x[j].second=max(a[j],c[j]);
	}
	for(int j=1;j<=n;j++){
		if(x[j].first==a[j]){m++;
		x[j].cc=1;
		}
		else if(x[j].first==b[j]){k++;
		x[j].cc=2;
		}
		else if(x[j].first==c[j]){l++;
		x[j].cc=3;
		}
		ans+=x[j].first;
	}
	
	sort(x+1,x+1+n,cmp);
	int ma=max(m,k);
	ma=max(ma,l);
	if(ma<=n/2)cout<<ans<<"\n";
	else{
		int f=-1;
		if(ma==m)f=1;
		else if(ma==k)f=2;
		else f=3;
		int bns=ma-n/2;
		for(int i=1;i<=n;i++){
			if(x[i].cc==f){
				ans-=x[i].first-x[i].second;
				bns--;
			}
			if(bns==0)break;
		}
		cout<<ans<<"\n";
	}
}
return 0;}

