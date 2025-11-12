#include<bits/stdc++.h>

typedef int IT;
typedef long long LL;
typedef __int128 int128;
typedef double DB;

#define pb push_back
#define fst first
#define sec second
#define psh push
#define PII pair<IT,IT>
#define PLI pair<LL,IT>
#define lowbit(x) ((x)&(-x))

using namespace std;

const int N=1e1+3,M=N;

//void qread(auto &sum){
//    sum=0;
//    auto f=sum+1;
//    char ch=getchar();
//    while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=getchar();}
//    while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-48;ch=getchar();}
//    sum*=f;
//    return;
//}
//
//void qp(auto x){
//    if(x>9) qp(x/10);
//    putchar(x%10+48);
//    return;
//}
//void qpp(auto x){
//    if(x<0) x=-x,putchar('-');
//    qp(x);
//    return;
//}

int n,m;
struct node{
	int val;
	int id;
}a[520];
bool cmp(node x,node y){
	return x.val>y.val;
}

PII ans[520];

int main(){
    freopen("seat.in","r",stdin);
//    freopen("seat3.in","r",stdin);
    freopen("seat.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i].val),a[i].id=i;
	
	sort(a+1,a+n*m+1,cmp);
	
	int p=1,q=1;
	int cur=1;
	for(int i=1;i<=n*m;i++){
		ans[a[i].id]={p,q};
		p+=cur;
		if(p>n){
			p=n;
			cur=-cur;
			q++;
		}
		else if(p<1){
			p=1;
			cur=-cur;
			q++;
		}
	}
	
//	for(int i=1;i<=n*m;i++) printf("%d %d\n",ans[i].fst,ans[i].sec);
	
//	printf("%d %d\n",ans[1].fst,ans[1].sec);
	// Please use your eyes to read the problems.
	printf("%d %d\n",ans[1].sec,ans[1].fst);
    return 0;
}
