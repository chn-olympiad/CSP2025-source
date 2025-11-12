#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
int n,m;
struct node{
	int g,p;
}a[110];
bool cmp(node x,node y){
	return x.g>y.g;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].g;
		a[i].p=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int P=-1;
	for(int i=1;i<=n*m;i++){
		if(a[i].p==1){
			P=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if((i-1)*n+n-j+1==P){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=1;j<=n;j++){
				if((i-1)*n+j==P){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
/*
吾日三省吾身：
freopen取消注释了乎？
文件名写对了乎？
样例过了乎？
*/