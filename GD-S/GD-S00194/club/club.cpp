#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005][4];
//struct node{
//	int val,x;
//};
//bool cmp(node a,node b){
//	return a.val>b.val;
//} 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n,b,c;
	cin>>T;
	while(T--){
		int n,cnt=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i]>>b>>c;
			}
		}
		sort(a+1,a+n+1);
		for(int i=n;i>=n/2;i--)ans+=a[i];
		cout<<ans<<endl;
	}
	return 0;
} 
