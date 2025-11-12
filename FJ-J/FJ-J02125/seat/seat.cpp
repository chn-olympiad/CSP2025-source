#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0; bool opt=true; char c=getchar();
	while(!isdigit(c)){ if(c=='-')opt=false; c=getchar(); }
	while(isdigit(c)){ x=x*10+c-48; c=getchar(); }
	return opt?x:-x;
}
inline void write(int x){
	static int s[20]; int top=0;
	if(x<0)putchar('-'),x=-x;
	if(x==0){ putchar('0'); return; }
	while(x){ s[++top]=x%10; x/=10; }
	while(top>0){ putchar(s[top--]+48); }
}
inline int _ceil(double x){
	return x==(int)x?x:((int)x)+1;
}
const int maxn = 105;
int a[maxn],Rscore,peo,_rank; // 分数 小R的分数 总人数 小R的排名 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=read(),m=read();
	peo=m*n;
	for(int i=0;i<peo;i++){
		a[i]=read();
	} // 读入 
	Rscore=a[0];
	sort(a,a+peo,greater<int>()); // 排序 
	for(int i=0;i<peo;i++){ // 求排名 
		if(a[i]==Rscore){
			_rank=i+1;
			break;
		}
	}
	int xx=_ceil(1.0*_rank/n); 
	write(xx);putchar(' ');
	if(xx&1){
		write(_rank%n==0?n:_rank%n);
	}else{
		write(n-(_rank%n==0?n:_rank%n)+1);
	}
	return 0;
} // 怎么这么爱考排序，T1T2都是排序 
// 总的来说T1T2橙题  T3T4绿题(猜的)  难度比较正常(至少没有蓝题) 
