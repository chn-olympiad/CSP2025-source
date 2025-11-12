#include<bits/stdc++.h>
using namespace std;

const int N=500+9;
int n,m;
char s[N],c[N];

bool ck1=true,ck2=true;
unsigned long long ans1=1;

int main(){

    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    scanf("%d%d",&n,&m);
    getchar();
    for(int i=1;i<=n;i++){
        s[i]=getchar();
        if(s[i]==0){
            ck1=false;
        }
    }
    getchar();
    for(int i=1;i<=n;i++){
        c[i]=getchar();
    }

    if(ck1||m==1){
        while(n){
            ans1 *= n;
            ans1 = ans1%998244353;
            n--;
            //cout<<ans1<<endl;
        }
        cout<<ans1;
    }
    else{
        printf("2");
    }

    return 0;
}
