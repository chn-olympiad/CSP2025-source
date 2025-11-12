#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005][10],s[100005][105],b[13];
void solve(){
	int n,k=-1;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			s[i][j]=-1;
		}
	}
	
	for(int i=1;i<=n;i++){
		int maxx=-1,t;
		for(int j=1;j<=3;j++){
			if(maxx<=a[i][j])
			{
				maxx=a[i][j];
				t=j;
				}
		}
		s[t][i]=a[i][t];
		b[t]++;
		if(b[t]>n/2) k=t;
	}
	int cnt=0;
	if(k==-1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(s[i][j]!=-1) cnt+=s[i][j];
			}
		}
		cout<<cnt<<"\n";
	}
	
	
	else {
		while(b[k]>n/2){
			int tt=0,mmm,nnn=1e9;	
		for(int i=1;i<=n;i++)
		{
			if(s[k][i]==a[i][k])
			{	
				if(k==1){
					mmm=max(a[i][2],a[i][3]);
				}else if(k==2){
					mmm=max(a[i][1],a[i][3]);
				}else if(k==3){
					mmm=max(a[i][1],a[i][2]);
				}
				if(s[k][i]-mmm<=nnn and s[k][i]!=-1)
			{
				nnn=s[k][i]-mmm;
				tt=i;
				}
			}
		}
		s[k][tt]=-1;
		b[k]--;
		cnt+=mmm;
	}
	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(s[i][j]!=-1) cnt+=s[i][j];
			}
		}
		cout<<cnt;
	}
	cout<<"\n";
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
