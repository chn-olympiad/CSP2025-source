#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long T;
struct node{
    long long a;
    long long b;
    long long c;
    long long maxn;
    long long z;
}a[100005];
bool cmp1(node x,node y){
	if(x.a!=y.a)
	    return x.a>y.a;
	else if(x.a==y.a&&x.b!=y.b)
	    return x.b>y.b;
	else if(x.a==y.a&x.b==y.b&&x.c!=y.c)
	    return x.c>y.c;
}
bool cmp2(node x,node y){
	if(x.b!=y.b)
	    return x.b>y.b;
	else if(x.b==y.b&&x.a!=y.a)
	    return x.a>y.a;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
		long long u1,u2,u3;
        long long n,mid,maxnn=0;
        long long ans1;
        scanf("%lld",&n);
        mid=n/2;
        for(int i=1;i<=n;++i){
            scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
            a[i].z=1;
            maxnn=max(a[i].b,a[i].a);
            a[i].maxn=max(maxnn,a[i].c);
		}

		long long cnt=0;
		for(int i=1;i<=n;++i){
            if(a[i].b==0&&a[i].c==0){
                cnt+=1;
            }
		}
		if(cnt==n){
            long long p=0;
			sort(a+1,a+1+n,cmp1);
            for(int i=1;i<=mid;++i){
                p+=a[i].a;
            }
        cout << p ;
		}

    }
    return 0;
}
