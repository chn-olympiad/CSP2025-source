#include<bits/stdc++.h>
using namespace std;
#define in(s1) freopen(s1,"r",stdin);
#define out(s1) freopen(s1,"w",stdout);
#define pii pair<int,int>
template<typename T>
inline void read(T &x){
	x=0;
	char c=getchar();
	int f=1;
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+(c-'0');
		c=getchar();
	}
	x*=f;
}
template<typename T>
inline void write(T x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
const int N=5e5+10;
int n,k;
int a[N],p[N];
bool csA(){
	for(int i=1;i<=n;i++)if(a[i]!=1)return false;
	return true;
}
bool csB(){
	for(int i=1;i<=n;i++)if(a[i]>1)return false;
	return true;
}
int main(){
	in("xor.in")
	out("xor.out")
	read(n),read(k);
	for(int i=1;i<=n;i++)read(a[i]);
	if(csA())write(n/2);
	else if(csB()){
		if(!k){
			int p=0,lx=0;
			for(int i=1;i<=n;i++)if(!a[i])p++;
			for(int i=1;i<=n;i++){
				if(!a[i])p+=lx/2,lx=0;
				else lx++;
			}
			p+=lx/2;
			write(p);
			return 0;
		}
		else{
			int p=0;
			for(int i=1;i<=n;i++)if(a[i])p++;
			write(p);
			return 0;
		}
	}
	else{
		int sum=0;
		for(int i=1;i<=n;i++)if(a[i]==k)sum++;
		write(sum);
	}
	return 0;
}

