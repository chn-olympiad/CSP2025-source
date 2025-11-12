#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
const ll INF=1e9+10;
ll ans=0;
int n=0;
int t=0;
ll value[4][N];
int count1=0;
int count2=0;
int count3=0;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		bool flaga=true;
		memset(value,0,sizeof value);
		for(int i=1;i<=n;i++){
			cin>>value[1][i]>>value[2][i]>>value[3][i];
			if(value[2][i]!=0||value[2][i]!=0){
				flaga=false;
			}
			
		}
		if(flaga){
				sort(value[1]+1,value[1]+1+n,cmp);
				for(int i=1;i<=n/2;i++){
					ans+=value[1][i];
				}
				cout<<ans<<endl;
				continue;
			} 
	}
	
} 
