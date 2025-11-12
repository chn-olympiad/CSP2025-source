#include <bits/stdc++.h>
#define ll long long
#define str string
#define N 500003
#define A 1048580
using namespace std;

bool st;
int a[N];
int f[N],g[A];
bool ed;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    fprintf(stderr,"%lf\n",(&ed-&st)/1024.0/1024);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(g,-0x3f,sizeof(g));
    g[0]=0;
    for(int i=1;i<=n;i++){
        a[i]^=a[i-1];
        f[i]=max(f[i-1],g[a[i]^k]+1);
        g[a[i]]=max(g[a[i]],f[i]);
    }
    printf("%d\n",f[n]);
    return 0;
}
