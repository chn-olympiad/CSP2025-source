#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[105],mark,sx[11][11],pt,id;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	mark=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==mark)id=i;
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				sx[j][i]=++pt;
				if(pt==id){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				sx[j][i]=++pt;
				if(pt==id){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}//#Shang4Shan3Ruo6Shui4
