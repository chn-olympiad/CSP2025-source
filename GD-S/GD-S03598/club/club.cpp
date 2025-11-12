#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e5+5;
int n,a[N][4],t[4];
struct node{
	int val,id;
}d[N];
bool cmp(node x,node y){return x.val>y.val;}
void print(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
		cout<<a[i][j]<<" ";
	}
	cout<<"\n";
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=3;i++)t[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		for(int i=1;i<=n;i++){
			int o=0,res=0;
			for(int j=1;j<=3;j++){
				if(a[i][j]>res){
					res=a[i][j];
					o=j;
				}
			}
			t[o]++;
		}
		int cnt=max(t[1],max(t[2],t[3]));
		if(cnt<=n/2){
			int ans=0;
			for(int i=1;i<=n;i++){
				int res=0;
				for(int j=1;j<=3;j++){
					res=max(res,a[i][j]);
				}
				ans+=res;
			}
			cout<<ans<<endl;
			continue;
		}
		if(cnt==t[2]){
			for(int i=1;i<=n;i++)swap(a[i][1],a[i][2]);
			swap(t[1],t[2]);
		}
		if(cnt==t[3]){
			for(int i=1;i<=n;i++)swap(a[i][1],a[i][3]);
			swap(t[1],t[3]);
		}
		//默认第一组是最多.
		int pp=cnt-n/2;
		int tot=0,ans=0;
//		print();
		for(int i=1;i<=n;i++){
			int p=max(a[i][1],max(a[i][2],a[i][3]));
			if(p==a[i][1]){
				tot++;
				d[tot].val=max(a[i][2]-a[i][1],a[i][3]-a[i][1]);
				d[tot].id=i;
			}
			ans+=p;
//			cout<<ans<<"mzk\n";
		} 
		sort(d+1,d+tot+1,cmp);
//		cout<<pp<<"!!!\n";
		for(int i=1;i<=pp;i++){
			ans+=d[i].val;
//			cout<<d[i].val<<"ena\n";
		}
		cout<<ans<<endl;
	}
	return 0;
} /*
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
