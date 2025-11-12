//##@@$%^&$^^%$#^$%^$^&^%&$^%$&$^$%&%^&  fuck
//ifdglDFGHDFHI$%^$#****&*&**^*&^*&*^*&^*&^
//$#%GFD*ERYRY(*^%(*Y%^YRT(%$(**#$%^%
#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int find(int x,int *a,int n){
    int l=0,r=n;
    while(l<=r){
        int mid=l+r>>1;
        if(a[mid]<=x) r=mid-1;
        else if(a[mid]>x) l=mid+1;
    }
    return l;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105]={0},R;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n*m;i++) scanf("%d",&a[i]);
    R=a[0];
    sort(a,a+n*m,cmp);
    int idx=find(R,a,n*m);
    int x=1,y=1;
    while(idx--){
        if(x%2==1){
            y++;
        }else{
            y--;
        }
        if(y>m||y<1){
            if(x%2==1){
                y=m;
                x++;
            }else{
                y=1;
                x++;
            }
        }
        if(x>n+2) {
            puts("fuck no answer gone!!!");
            return 0;
        }
    }
    printf("%d %d\n",x,y);
    return 0;
}
