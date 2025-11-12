#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m,x,ans;
int s[110][110];
int a[10010];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(x==a[i]){
			ans=i;
		}
	}
	int w=0;
	int xx=1;
	int yy=1;
	for(int i=1;i<=m*n;i++){
		w++;
		if(ans==w){
			cout<<yy<<" "<<xx;
			return 0;
		}
		if(yy%2==1){
			if(xx+1<=n){
				xx++;
				continue;
			}else{
				xx=n;
				yy++;
				continue;
			}
			continue;	
		}
		if(yy%2==0){
			if(xx-1>=1){
				xx--;
				continue;
			}else{
				xx=1;
				yy++;
				continue;
			}
			continue;
		}
	}
	return 0;
}