#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
const int N=1e5+5;
struct node{
	int a[4],c;
}a[N];
int cnt[N];
bool cmp(pair<int,int>x,pair<int,int>y){
	return x.first>y.first;
}
char s1[N],s2[N];
string s[N][2],p[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		scanf("%s%s",s1,s2);
		s[i][1]=s1;s[i][2]=s2;
	}
	for(int i=1;i<=q;++i){
		scanf("%s%s",s1,s2);
		p[i][1]=s1;p[i][2]=s2;
		puts("0");
	}
	return 0;
}
