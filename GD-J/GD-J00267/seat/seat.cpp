#include<bits/stdc++.h>
using namespace std;

const int N=1e2+10;
int n,m,a[N],rs,nr; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	rs=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==rs){
			nr=n*m-i+1;
			break;
		}
	}
	int ro=nr/n,co=nr%n;
	if(co) ro++;
	if(!co) co=n;
	if(ro%2==0){
		co=n-co+1;
	}
	cout<<ro<<' '<<co;
	
	return 0;
}
/*
2 2
98 99 100 97
2 2
99 100 97 98
3 3
94 95 96 97 98 99 100 93 92
*/

//这数据量闹着玩呢
//1e2还是第一次见 
