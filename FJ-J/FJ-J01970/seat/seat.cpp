#include <bits/stdc++.h>
using namespace std;
int n,m,f,s,now=0,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	f=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==f){
			s=i;
			break;
		}
	}
//	cout<<f<<' '<<s;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				now++;
				if(now==s){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		if(i%2==0){
			for(int j=m;j>=1;j--){
				now++;
				if(now==s){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
