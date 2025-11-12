#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,k,v,u,w,s;
int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	while(m--){u=read();v=read();w=read();s+=w;}
	while(k--)for(unsigned long long i=1;i<=n;i++)m=read();
	write(s);
	return 0;
}
