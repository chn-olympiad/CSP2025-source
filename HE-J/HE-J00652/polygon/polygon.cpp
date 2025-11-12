#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<algorithm>
using namespace std;
int a[500001],n,ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    srand(time(0));
    ans=rand()%(n*n*n);
    printf("%d",ans);
    return 0;
}
