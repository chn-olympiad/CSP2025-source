#include <bits/stdc++.h>
using namespace std;
int read(){
	int x=0, f=1;
	char c=getchar();
	while(c>'9' || c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9' && c>='0'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
const int N=5e5+5;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n=read(), k=read(), sum=0;
	bool flag=false;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]==0){
			sum++;
			flag=true;
		}
	}
	if(k==0){
		if(n<=1){
			cout << 0;
		}
		else{
			cout << 2;
		}
	}
	else if(k==1){
		if(n<=0){
			cout << 0;
		}
		else if(n==1 && a[1]==1){
			cout << 1;
		}
		else if(flag){
			cout << 2;
		}
		else cout << 1;
	}
	else{
		cout << 3 << endl;
	}
	return 0;
}
