#include<bits/stdc++.h>
using namespace std;
inline unsigned long read(){
	unsigned long x=0;
	char ch=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
unsigned long n,k;
unsigned long a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();
	k=read();
	a[1]=read();
	for(unsigned int i=2;i<=n;i++)a[i]=(read()^a[i-1]);
	int x=1,maxx=0;
	for(unsigned int i=1;i<=n;i++){
		for(unsigned int j=x;j<=i;j++){
			if((a[i]^a[j-1])==k){
				x=i+1;
				maxx++;
				break;
			}
		} 
	}
	cout<<maxx;
	return 0;
}
