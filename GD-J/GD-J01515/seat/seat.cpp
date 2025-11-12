#include<bits/stdc++.h>
using namespace std;

namespace A{
	
	int read(){
		int x=0,f=1;char c;c=getchar();
		while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
		while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
		return x*f;
	}
	int n,m,g[105],x;
	int a=1,b=1,k=1;
	
	void f(){
		while(k<x){
			while(a<n){
				a++;k++;
				if(k==x)return ;
			}
			b++;k++;
			if(k==x)return;
			while(a>1){
				a--;k++;if(k==x)return ;
			}
			b++;k++;
			if(k==x)return;
		}
	}
	
	void Solve(){
		n=read();m=read();
		for(int i=1;i<=n*m;i++)g[i]=read();
		x=g[1];
		sort(g+1,g+1+n*m);
		for(int i=1;i<=n*m;i++)if(g[i]==x){
			x=n*m-i+1;
			break;
		}
		f();
		printf("%d %d",b,a);
	}
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	A::Solve();
	return 0;
} 
