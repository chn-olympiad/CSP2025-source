#include <bits/stdc++.h>
using namespace std;
int n,k,a[500010],b[500010],maxx=-1;
int xoor(int x,int y){
	string s;
	int anns;
	while(x||y){
		if(x%2==y%2){
			s+='0';
		}
		else{
			s+='1';
		}
		x/=2;
		y/=2;
	}
	for(int i=0;i<s.size();i++){
		anns=anns+(s[i]-'0')*pow(2,i);
	}
	return anns;
}
void f(int num){//youjigeshumeifen,yijingfenlejigequkuai
	int cnt=0;
	if(num==0){
		for(int i=1;i<=n;i++){
			if(b[i]==k) cnt++;
		}
		maxx=max(maxx,cnt);
		return;
	}
	for(int i=1;i<=num;i++){
		int sum=0;
		for(int j=n-num;j<n-num+i;j++){
			sum=xoor(sum,a[j]);
		}
		b[i]=sum;
		f(num-i);
		b[i]=0;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	f(n);
	cout<<maxx;
	return 0;
}
/*
google.surf.com
4 3
2 1 0 3
*/
