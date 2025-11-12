#include <bits/stdc++.h>
using namespace std;
int a,b;
int c[101];
int main(){
	freeopen("seat.in","r",stdin);
	freeopen("seat.out","w",stdout);
	cin>>a>>b;//aĞĞbÁĞ 
	int cnt=1;
	for(int i=1;i<=a*b;i++){
		cin>>c[i];
		if(c[i]>c[1]) cnt++;
	}
	int d=2*a;
	
	if(cnt%a==0){
		cout<<cnt%a<<' ';
	} 
	else cout<<cnt/a+1<<' ';
	if(cnt%d>a) cout<<a-cnt%a+1;
	else cout<<cnt%a;
	return 0;
} 
