#include<bits/stdc++.h>
using namespace std;
int a[15][15],n,m,b[200],s=0,cnt=0;
bool cmp(int s,int t){
	return s>t;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	b[1]=s;
	for(int i=2;i<=n*m;i++)cin>>b[i];
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				cnt++;
				if(b[cnt]==s){
					cout<<i<<' '<<j;
					break;
				}
			}
		}else{
			for(int j=1;j<=n;j++){
				cnt++;
				if(b[cnt]==s){
					cout<<i<<' '<<j;
				}
			}
		}
	}
	return 0;
}
