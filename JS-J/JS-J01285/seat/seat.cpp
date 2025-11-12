#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[105],R,len;
FILE *fin,*fout;
int c,r;
bool cmp(int x,int y){
    return x>y;
}
void aaa(int x,int y){
    while(x<y){
        swap(a[x],a[y]);
        x++;
        y--;
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    len=n*m;
    for(int i=1;i<=len;i++)scanf("%d",a+i);
    R=a[1];
    sort(a+1,a+len+1,cmp);
    for(int i=n+1;i<=len;i+=n+n)aaa(i,i+n-1);
    /**/
    int top=1;
    bool aa=0;
    for(int i=1,j=1,d;i<=m;i++){
        d=((i%2)?1:-1);
        for(;j>=1 && j<=n;j+=d)
            if(a[top]==R){
                c=i;
                r=j;
                aa=1;
                break;
            }
        if(aa)break;
        top++;
        if(j<1)j=1;
        else if(j>n)j=n;
    }
    printf("%d %d",c,r);
    return 0;
}
