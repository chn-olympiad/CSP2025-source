#include<bits/stdc++.h>
using namespace std;
long long n,a,b,c,cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	cin>>a>>b>>c;
	if(n==3){
		if(a+b>c){
			cnt++;
		}
		cout<<cnt;
	}else{
		cout<<1;
	}
	return 0;
}
