#include<bits/stdc++.h>
const int C=998244353;
using namespace std;
fstream("polygon.in","r",stdin);
fstream("polygon.out","w",stdout);
int a[5005];
int choose[5005]={0};

int sum_a(int do_you_want_an_oppo){
	int no_thank_you=0;
	for(int oh_sorry = 1;oh_sorry<=do_you_want_an_oppo;oh_sorry++){
		no_thank_you+=a[choose[oh_sorry]];
	}
	return no_thank_you;
}
int gotta(int n){
	if(sum_a(n)>2*choose[n]){
		return 1;
	}
	return 0;
}
int solve(int n,int c,int route){
	int count=0;
	if(n+1==c){
		return gotta(n);
	}
	for(int i = choose[c-1]+1;i<=route-n+c;i++){
		choose[c]=i;
		//if(a[choose[c]]==a[choose[c]-1] && choose[c]!=choose[c-1])continue;
		count+=solve(n,c+1,route);
		count%=C;
	}
	return count%C;
}
int f(int n){
	int c=0;
	for(int i = 3;i<=n;i++){
		c+=solve(i,1,n);
		c%=C;
	}
	return c%C;
}
int main(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<f(n);
	return 0;
}
