#include<bits/stdc++.h>
using namespace std;
int a[1000005],n,m,k,ans,tot=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",a+i);
        if(i!=1&&a[i]>a[1]) tot++;
    }
    int s1=tot/n,s2=tot%n;
    if(s2==0){
        if(s1&1) cout<<s1<<' '<<n<<'\n';
        else cout<<s1<<' '<<1<<'\n';
    }else{
        if(s1&1) cout<<s1+1<<' '<<n-s2+1<<'\n';
        else cout<<s1+1<<' '<<s2<<'\n';
    }
    
    return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92

2 2
98 99 100 97
*/
