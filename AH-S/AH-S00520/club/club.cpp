#include<bits/stdc++.h>
using namespace std;
const int N=100000+10;
int t,n;
int a[N],b[N],c[N],d[N],dp[100001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		bool flag=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		if(n>30){
			for(int i=1;i<=n;i++)
				if(b[i]!=0&&c[i]!=0) flag=1;
			sort(a+1,a+n+1,cmp);
			if(!flag){
				int ans=0;
				for(int i=1;i<=n/2;i++) ans+=a[i];
				cout<<ans<<"\n";
			}
		}
		
	}
	
	return 0;
}
/*
 * 
 */
