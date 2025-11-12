#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e2+5;
int a[MAXN],n,m,vis[MAXN],sc;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	sc=a[1];
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[++cnt]==sc){
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[++cnt]==sc){
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
