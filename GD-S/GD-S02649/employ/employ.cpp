#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
struct p{
	int idx,cs;
	bool operator < (const p a){
		return idx<a.idx;
	}
}c[100010];
int n,m,sum[100010],ans;
string s;
bool b[100010];

bool okay(){
	int tmp=0,gi=0;
//	for(int i=1;i<=n;i++) printf("%d ",c[i].cs);
//	printf("\n");
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			gi++;
		}else if(gi>=c[i].cs){
			gi++;
		}else tmp++;
//		printf("i=%d\tgi=%d\ttmp=%d\n",i,gi,tmp);
	}
	return (tmp>=m);
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s,s=" "+s;
	for(int i=1;i<=n;i++) scanf("%d",&c[i].cs),c[i].idx=i;
	sort(c+1,c+1+n);
	do{
		ans=(ans+okay())%mod;
	}while(next_permutation(c+1,c+1+n));
	printf("%d\n",ans);
	return 0;
}
