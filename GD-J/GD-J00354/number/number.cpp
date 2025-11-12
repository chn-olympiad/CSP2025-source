#include<cstdio>
#include<cstdlib>
typedef long long LL;
const int N=1e6+3;
char s[N], stmp[N];
int k=0;//k个数字字符
 
template<typename AU>
void sort(AU *alpha, AU *beta, int l, int r) {//将alpha[l..r]降序排序
	if(l>=r) return ;
	int md=(l+r)>>1;
	sort(alpha,beta,l,md), sort(alpha,beta,md+1,r);
	int i=l, j=md+1, t=l;
	while(i<=md&&j<=r) (alpha[i]>=alpha[j])? (beta[t++]=alpha[i++]) : (beta[t++]=alpha[j++]);
	while(i<=md) {beta[t++]=alpha[i++]; }  while(j<=r) beta[t++]=alpha[j++];
	for(i=l; i<=r; ++i) alpha[i]=beta[i];
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&s[1]);
	for(int i=1;s[i];++i) {
		if(s[i]>=48&&s[i]<=57) s[++k]=s[i];//如果这个是数字字符
	}
	sort(s,stmp,1,k);
	for(int i=1;i<=k;++i) putchar(s[i]);
	return 0;
}

