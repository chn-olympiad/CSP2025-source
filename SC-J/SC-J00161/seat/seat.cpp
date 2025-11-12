#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[105],shu;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			shu=a[i];
		}
	}
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(shu==a[i]){
			int l=(n*m-i)/n+1,h=0;
			if(l%2==0){
				h=n-((n*m-i+1)-n*(l-1))+1;
			}else{
				h=(n*m-i+1)-n*(l-1);
			}
			cout<<l<<" "<<h;
			return 0;
		}
	}
	return 0;
}