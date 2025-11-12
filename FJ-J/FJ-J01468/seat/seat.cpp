#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+(c-'0'),c=getchar();
	return x*f;
}
int n,m;
int a;
int sum;
int x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();a=read();sum=1;
	for(int i=2;i<=n*m;i++)if(a<read())sum++;
//	cout<<sum<<endl;
	x=(sum-1)/n+1;
	if(x&1)y=(sum-1)%n+1;
	else y=n-(sum-1)%n;
	printf("%d %d",x,y);
	return 0;
}

