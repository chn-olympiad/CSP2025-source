#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define dbg(x) cout<<#x<<'='<<x<<endl;
#define ll long long
int a[1010];
int b[110][110];
bool cmp(int A,int B){
	return A>B;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int pos;
	for(int i=1;i<=n*m;i++)if(a[i]==r)pos=i;
	int tot=1;
	for(int j=1;j<=m;j++){
		if(j&1){
			for(int i=1;i<=n;i++){
				b[i][j]=tot++;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				b[i][j]=tot++;
			}
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		if(b[i][j]==pos){
			cout<<j<<" "<<i<<endl;
			return 0;
		}
	}
	return 0;
}
