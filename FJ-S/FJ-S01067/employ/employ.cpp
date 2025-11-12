#include <bits/stdc++.h>
#define File(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
const int MAXN = 503;
int n, m, c[MAXN], a[MAXN], b[MAXN], s[MAXN];
long long ans;
const long long MOD = 998244353;
bool cmpc1(int a,int b){
	return a>b;
}

long long uc(int l) {
	if(l==0) return 1;
	if(l<0) return 0;
	return l*uc(l-1)%MOD;
}
long long gl(int i,int l) {
//	printf("gl:%d- %d=%d\n",i,l,b[i]);
	if(i<0){
		if(l<m) return 0;
		else return 1;
	}
	if(l==m) return uc(i+1);
	if(a[i]==0) return (gl(i-1,l)*(1+i)%MOD);
	return (gl(i-1,l+1)*(b[i]-n+i+1)+gl(i-1,l)*(i+1-b[i]))%MOD;
}
int main () {
	File("employ");
	scanf("%d%d",&n,&m);
	char f;
	do scanf("%c",&f);
	while(f!='0' && f!='1');
	int i = 0, j;
	a[i] = f - '0';s[i+1] =s[i]+1-a[i];
	for(i = 1; i < n; a[i] = f - '0', s[i+1] = s[i]+1-a[i], i++) scanf("%c", &f);
	for(i = 0; i < n; i++) scanf("%d", &c[i]);
	std::sort(c,c+n,cmpc1);
//	for(i = 0; i < n; i ++) printf("%d ",a[i]);printf("\n");
	for(ans = 1, i = 0, j = n-1;i < n; /*a[i]=j+1,*/i++) for(; j >=0 && s[j]>=c[i];b[j] = i, j-- );
	for(j = 0; b[j]==0; b[j]=n,j++);
//	for(i = 0; i < n; i ++) printf("%d ",c[i]);printf("\n");
//	for(i = 0; i <=n; i ++) printf("%d ",s[i]);printf("\n");
//	for(i = 0; i < n; i ++) printf("%d ",a[i]);printf("\n");
//	for(i = 0; i < n; i ++) printf("%d ",b[i]);printf("\n");
//	for(j = n -1 ; j>-1;j--) ans = ans * (b[j]-n+1+j) %MOD;

	printf("%lld\n", gl(n-1,0));
	return 0;
}

