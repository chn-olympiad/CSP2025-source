#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[105],rn,p;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	rn=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			p++;
			if(a[p]==rn){
				cout<<i<<" "<<j;
				return 0;
			}
		}
		i++;
		if(i>m){
			break;
		}
		for(int j=n;j>=1;j--){
			p++;
			if(a[p]==rn){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
