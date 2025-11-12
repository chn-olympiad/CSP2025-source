#include <bits/stdc++.h>
using namespace std;
long long read(){
	long long ans=0;
	char c;
	c=getchar();
	while(c<'0' or c>'9')c=getchar();
	while(c>='0' && c<='9'){
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans;
}
long long n,m,a[1111],sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	m=read();
	n=read();
	for(int i=1;i<=n*m;i++){
		a[i]=read();
		if(a[i]>=a[1])sum++;
	}
	cout<<(sum+m-1)/m<<" ";
	if(((sum+m-1)/m)%2==1){
		cout<<(sum-1)%m+1;
	}else{
		cout<<m-(sum-1)%m;
	}
	return 0;
} 
