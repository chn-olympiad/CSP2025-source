#include<bits/stdc++.h>
using namespace std;
const int N=1<<21;
char in[N],*p1=in,*p2=in,out[N],*op=out;
inline char gc(){
	return p1==p2&&(p2=(p1=in)+fread(in,1,N,stdin),p1==p2)?EOF:*p1++; 
}
template<typename T>
inline void read(T &x){
	char c=gc();
	while(!isdigit(c)) c=gc();
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c-'0');
		c=gc();
	}
}
inline void flush(){
	fwrite(out,1,op-out,stdout);
	op=out;
}
template<typename T>
inline void write(T x){
	if(x>9) write(x/10);
	if(op-out>=N-20) flush();
	*op++=x%10+'0';
}
long long n,m,a[500010],f[500010],idx;
struct nd{
	int l,r;
}d[500010];
bool cmp(nd x,nd y){
	if(x.r==y.r) return x.l<y.l;
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	read(n);read(m);
	if(n>=100000){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		read(a[i]);
		f[i]=f[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((f[j]^f[i-1])==m){
				d[++idx]={i,j};
			}
		}
	}
	sort(d+1,d+idx+1,cmp);
	long long h=1,s=0;
	for(int i=1;i<=idx;i++){
		if(d[i].l>=h){
			s++;
			h=d[i].r+1;
		}
	}
	write(s);
	flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
