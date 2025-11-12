#include<bits/stdc++.h>
using namespace std;
int n,m;
struct st{
	int ex;
	int id;
}a[105];
bool cmp(st x,st y){
	return x.ex>y.ex;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].ex;
	a[1].id=1;
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt++;
				if(a[cnt].id==1){
					cout<<i<<" "<<j;
					break;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(a[cnt].id==1){
					cout<<i<<" "<<j;
					break;
				}
			}
		}
	}
	return 0;
}
