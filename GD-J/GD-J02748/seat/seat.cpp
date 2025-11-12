#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >>a[i];
	}int aa=a[1],b=0;
	sort(a+1,a+n*m+1,greater<int>());
	for(int i = 1;i <= n*m;i++){
		if(aa==a[i]){
			b=i;
			break;
		}
	}int c=b%n,d=b/n;
	//for(int i = 1;i <= n*m;i++)cout << a[i]<<' ';
	if(c==0){
		if(d&1){
			cout << d<<' '<<n;
		}else cout <<d<<' '<<1;
	}else{
		d++;
		if(d&1){
	    	cout << d<<' '<<c;
		}else cout << d<<' '<<n-c+1;
	}//cout << b;
	return 0;
}//3 3 
//94 95 96 97 98 99 100 93 92

