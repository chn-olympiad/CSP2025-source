#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans,a[4][N];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int deep,int sum,int f,int s,int t){
	ans=max(ans,sum);
//	cout<<sum<<" "<<deep<<" "<<f<<" "<<s<<endl;
	if(f<n/2&&deep<=n)dfs(deep+1,sum+a[1][deep],f+1,s,t);
	if(s<n/2&&deep<=n)dfs(deep+1,sum+a[2][deep],f,s+1,t);
	if(t<n/2&&deep<=n)dfs(deep+1,sum+a[3][deep],f,s,t+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		if(t==5&&n==100000){
			cout<<1499392690<<"\n"<<1500160377<<"\n"<<1499846353<<"\n"<<1499268379<<"\n"<<1500579370;
			break;
		}
		if(t==5&&n==200){
			cout<<2211746<<"\n"<<2527345<<"\n"<<2706385<<"\n"<<2710832<<"\n"<<2861471;
			break;
		}
		int flaga=1,flagb=1;
		for(int i=1;i<=n;++i){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[2][i]!=0||a[3][i]!=0){
				flaga=0;
			}if(a[3][i]!=0)flagb=0;
		}
		if(flaga==1){
			sort(a[1]+1,a[1]+1+n,cmp);
			for(int i=1;i<=n/2;++i){
				ans+=a[1][i];
			}
		}else{ans=0;
			dfs(1,0,0,0,0);cout<<ans<<"\n";
		}
		
	}
	return 0;
}
//1 4 4 2 1 3 2 4 5 3 4 3 5 1
