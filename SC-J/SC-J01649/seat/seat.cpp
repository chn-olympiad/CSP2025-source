#include<cstdio>
int n,m,R,cnt=1,a;
int main(){
    freopen("seat.in","r",stdin),freopen("seat.out","w",stdout);
    scanf("%d%d%d",&n,&m,&R);
    for(int i=1;i<n*m;i++)scanf("%d",&a),cnt+=a>R;
    int cp1=cnt/(2*n),cp2=cnt%(2*n);
    if(cp2==0)printf("%d %d",cp1*2,1);
    else if(cp2<=n)printf("%d %d",cp1*2+1,cp2);
    else printf("%d %d",cp1*2+2,2*n-cp2+1);
}