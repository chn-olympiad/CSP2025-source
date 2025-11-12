#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int a[1000];
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)
        scanf("%d",&a[i]);
    int ma=a[1];
    sort(a+1,a+(n*m)+1);
    int n1=0,m1=1;
    int i=n*m;
    bool f=false;
    while(a[i]>=ma){
        if(n1==n&&f==false||(n1==1&&m1!=1)){
            m1++;
            i--;
            f=true;
            continue;
        }
        if(m1%2==1){
            n1++;
        }
        else
            n1--;
        i--;
        f=false;
    }
    printf("%d %d",m1,n1);
    return 0;
}
