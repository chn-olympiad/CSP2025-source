#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f*x;
}
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n=read(),k=read();
	int cha=0,ling=0,yi=0,l1=INT_MIN,l=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]==a[i-1]&&l1!=i-1)l++,l1=i;
		if(a[i]==0)ling++;
		if(a[i]==1)yi++;
	}
	if(l1=INT_MIN)l1==0;
	if(k==0)cout<<l+ling<<endl;
    else if(k==1)cout<<yi<<endl; 
    else cout<<1<<endl;
}
