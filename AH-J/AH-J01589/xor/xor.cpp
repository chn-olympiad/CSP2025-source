//代码错的,别看了
//SDFSDFWE%$#&^&*^%&%^&@#$@$
//%$#%$^&*^^&*^&*%^$&%&^%&%$^&$
#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
    int l;
    int r;
}tp[100005],last;
int a[105]={0},s[105]={0};
bool cmp(const node &a,const node &b){
    if(a.l!=b.l) return a.l<b.l;
    else return a.r<b.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0,l;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(i==0) s[i]=a[i];
        else s[i]=s[i-1]^a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if((s[j]^s[i-1])==k){
                ans++;
		i=j;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
