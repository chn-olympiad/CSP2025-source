#include <bits/stdc++.h>
using namespace std;
int n,m,a[100010],s[100010],aon,c=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	aon=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		s[i]=a[i];
	}
	for(int i=1;i<=m;i++){
		if(i%2==0){
			c=n;
		}
		else c=1;
		
		for(int j=i*n-n+1;j<=i*n;j++){
			if(s[j]==aon){
				cout<<i<<' '<<c;
				break;
			}
			if(i%2==0){
			c--;
		}
		else c++;
		}
	}
	return 0;
}
