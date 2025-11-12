#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+10;
struct node{
	int num,x,y;
};
node a[N];
bool cmp(node a,node b){
	return a.num>b.num;
}
signed main(){
//	freopen("club.in","r",stdin);
//	freopen("club.in","w",stdout);	
	int t;cin>>t;
	while(t--){
		int n,ans=0,cnt[4]={0,0,0,0};
		int tall=0;
		cin>>n;
		bool vis[N];
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				cin>>a[++tall].num;
				a[tall].x=i;a[tall].y=j;
			}
			vis[i]=0;		
		}
		sort(a+1,a+tall+1,cmp);
//		cout<<t<<"---------"<<endl;
//		for (int i=1;i<=tall;i++){
//			cout<<a[i].x<<":"<<a[i].y<<"->"<<a[i].num<<endl;
//		}
		for (int i=1;i<=tall;i++){
			if (vis[a[i].x]==0&&cnt[a[i].y]<n/2){
				vis[a[i].x]++;cnt[a[i].y]++;
				ans+=a[i].num;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
