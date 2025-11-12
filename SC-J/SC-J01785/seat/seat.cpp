#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[105],sc,cnt;
bool cmp(int a1,int a2){
	return a1>a2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	sc=a[1];
	sort(a+1,a+n*m+1,cmp);//降序
	cnt=1;
	for(int j=1;;){
		for(int i=1;i<=n;i++){
			if(a[cnt]==sc){
				cout<<j<<" "<<i;
				return 0;
			}
			cnt++;
		}
		j++;
		for(int i=n;i>=1;i--){
			if(a[cnt]==sc){
				cout<<j<<" "<<i;
				return 0;
			}
			cnt++;
		}
		j++;
	}
}