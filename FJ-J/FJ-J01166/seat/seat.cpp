#include <bits/stdc++.h>
#define int long long
#define y0 __Y0
#define y1 __y1
#define pb push_back
#define pii pair<int,int>
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define file(x) freopen(x".in","r",stdin);
using namespace std;
const int N=1005;
int n,m,a[N],R,top=0;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	FILE("seat")
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i=1,j=1;
	while(1){
		if(i==n&&j==m){
			cout<<j<<" "<<i;
			break;
		}
		if(a[++top]==R){
			cout<<j<<" "<<i;break;
		}
		if(j%2==1){
			if(i==n){
				j++;
			}
			else{
				i++;
			}
		}
		else if(j%2==0){
			if(i==1){
				j++;
			}
			else{
				i--;
			}
		}
	}
	return 0;
}
