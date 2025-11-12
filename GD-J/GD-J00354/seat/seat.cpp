#include<cstdio>
#include<cstdlib>
typedef long long LL;
const int N=13, M=13, S=103;
int n, m, s, a[S], c[S], r[S];//c[x], r[x]: 排名第x的同学在第几行第几列 
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%i%i",&n,&m);  s=n*m;
	for(int i=1;i<=s;++i) scanf("%i",&a[i]);
	int a1=a[1], tc=1, tr=1, x=0;//提前记住小R的位置 
	while(tc<=m) {//填充各个人的位置 
		++x, c[x]=tc, r[x]=tr;
		//奇下偶上 
		if(tc&1) { if(tr==n) ++tc;  else ++tr; }//到达/没到达底部
		else {if(tr==1) ++tc; else --tr; }//偶数也如此
	}
	for(int i=1;i<=s;++i) {//因为s很小（<=100），所以可以O(s^2)排序 
		for(int j=i+1;j<=s;++j) if(a[i]<a[j]) a[0]=a[i], a[i]=a[j], a[j]=a[0];
	}
	for(int i=1;i<=s;++i) {
		if(a[i]==a1) {printf("%i\x20%i",c[i],r[i]); return 0; }//这个是小R 
		//因为题目说了不会重分，所以可能的小R只有1个 
	} return 0;
}
