#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,r,c;
struct Stu{
	int sc,k;
	bool operator < (const Stu x)const{
		return sc>x.sc;
	}
}s[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&s[i].sc),s[i].k=i;
	sort(s+1,s+n*m+1);
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)
	    if(s[(i-1)*n+j].k==1)r=i,c=j;
	if(r%2==0)c=(n+1)-c;
	printf("%d %d",r,c);
	return 0;
}
