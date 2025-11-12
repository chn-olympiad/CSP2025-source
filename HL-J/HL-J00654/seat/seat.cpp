#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int a[N],n,m,score,num;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=(n*m);i++){
		cin >> a[i];
		if(i==1){
			score=a[i];
		}
		
	}
	sort(a+1,a+1+(n*m));
	for(int i=1;i<=(n*m);i++){
		if(a[i]==score){
			num=(n*m)-i+1;
			break;
		}
	}
	int l=ceil(num*1.0/n);
	int p=num%m;
	int h;
	if(l%2==1){
		h=p;
	}else{
		h=m-p+1;
	}
	cout << l <<' ' << h;
//2 2
//99 100 97 98

//2 2
//98 99 100 97

//3 3
//94 95 96 97 98 99 100 93 92
	return 0;
}