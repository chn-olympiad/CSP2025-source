#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500005], s[500005], ans=0, sum=0, x, y;
int d[3005][3005];
int lowbit(int i){
    return i&(-i);
}
struct node {
    int l, r;
}p[2000005];
bool cmp(node x, node y){
    if (x.r==y.r) return x.l<y.l;
    else return x.r<y.r;
}
void tsb(){
	long long sum1=0, sum2=0, sum3=0;
	int t=1;
	for (long long i=1; i<=n; i=i){
		if (a[t]==1){
			sum3=0;
		    while (a[t]==1 && t<=n){
			    sum1++;
			    sum3++;
			    t++;
		    }
		    sum2+=sum3/2;
		    i=t;
		}else i++, t=i;
	}
	/*for (int i=1; i<=n; i++){
		if (a[i]==1) sum4++;
	}*/
	if (k==1){
		printf("%lld", sum1);
	}else{
		printf("%lld", n-sum1+sum2);
	}
	return;
}
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%lld%lld", &n, &k);
    s[0]=0;
    int tmp=0;
    for (int i=1; i<=n; i++){
        scanf("%lld", &a[i]);
        s[i]=s[i-1]^a[i];
        if (a[i]>1) tmp=1;
    }
    if (n>1000 && !tmp){
		tsb();
		return 0;
	}
    for (int i=1; i<=n; i++){
        for (int j=i; j<=n; j++){
            d[i][j]=s[j]^s[i-1];
            if (d[i][j]==k){
                p[++sum].l=i; p[sum].r=j;
            }
        }
    }
    sort(p+1, p+sum+1, cmp);
    x=0, y=0;
    for (int i=1; i<=sum; i++){
        if (p[i].l>y){
            ans++;
            x=p[i].l, y=p[i].r;
            //cout << x << ' ' << y << '\n';
        }
    }
    printf("%lld", ans);
    return 0;
}
