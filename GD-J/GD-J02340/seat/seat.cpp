#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=110;
int n,m,a[N*N],k,cnt;
bool flag;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		if(flag)break;
		if(i%2==1){
			for(int j=1;j<=m;j++){
				cnt++;
				if(a[cnt]==k){
					cout<<i<<' '<<j;
					flag=true;
					break;
				}
			}
		}
		else{
			for(int j=m;j>=1;j--){
				cnt++;
				if(a[cnt]==k){
					cout<<i<<' '<<j;
					flag=true;
					break;
				}
			}
		}
	}
	return 0;
} 
