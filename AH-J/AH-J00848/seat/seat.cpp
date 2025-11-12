#include<bits/stdc++.h>
using namespace std;
int n,m,fs,cnt=1;
int a[100005],mp[105][105];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++) cin>>a[i];
	fs=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n*m;i++){
		if(a[i]==fs){
			cnt=i;
			break;
		}
	}
	for(int i = 1;i <= n;i++){
		mp[i][1]=i;
		if(mp[i][1]==cnt){
			cout<<1<<" "<<i;
			return 0;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(j==1) continue;
			if(j%2==0){
				mp[i][j]=mp[i][j-1]+(n-i)*2+1;
			}else{
				mp[i][j]=mp[i][j-1]+(i-1)*2+1;
			}
			if(mp[i][j]==cnt){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
/*3 3
 94 95 96 97 98 99 100 93 92
 */
