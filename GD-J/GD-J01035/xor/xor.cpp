#include<cstdio>
#include<algorithm>
#define pen putchar('\n')
#define pk putchar(' ')
using namespace std;
int n,k,l,cnt,cnt1,cnt2,ans=0,a[500001];
bool v[500001],no=false;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	if(n==1) {
		if(k==a[1]) putchar('1');
		else putchar('0');
		return 0;
	}
	else if(n==2) {
		if(a[1]==a[2]&&a[1]==k) putchar('2');
		else if(a[1]!=a[2]&&(a[1]==k||a[2]==k)) putchar('1');
		else if(a[1]==a[2]&&a[1]!=k) putchar('1');
		else putchar('0');
		return 0;
	}
	else 
		for(int r=1;r<=n;++r) 
			for(int c=r,ls=0;c<=n;++c) {
				no=false,ls=0;
				for(int i=r;i<=c&&!no;++i) (!v[i])?(ls^=a[i]):(no=true);
				if(ls==k&&!no) {
					ans++;
					for(int i=r;i<=c;++i) v[i]=true;
				}
			}
	printf("%d",ans);
	return 0;
}
//补药骂我，我真的只想到了暴力
//愿RP++ 
