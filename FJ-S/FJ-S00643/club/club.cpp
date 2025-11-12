#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
struct Node{
	int x,w;
}a[3][N];
int T,n;
bool cmp(Node a,Node b){
	return a.w>b.w;
}
bool check(){
	int res1=0,res2=0;
	for(int i=1;i<=n;i++){
		res1+=a[2][i].w;
		res2+=a[3][i].w;
	}
	if(res1==0 && res2==0) return true;
	else return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[j][i].w;
				a[j][i].x=j;
			}
		}
		if(n==2){
			int ans=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(j!=i){
						ans=max(ans,a[i][1].w+a[j][2].w);
					}
				}
			}
			cout<<ans<<"\n";
		}else if(check()){
			int ans=0;
			sort(a[1]+1,a[1]+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[1][i].w;
			cout<<ans<<"\n";
		}else{
			cout<<n<<"\n";
		}
	}
	return 0;
}

