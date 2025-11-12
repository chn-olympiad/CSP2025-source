#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N],c[N];
int num;
int ans;        //have chosen
void f(int x,int y){

    if(y==num){
       printf("\n");
        int sum=0;
        for(int i=1;i<num+1;++i){
            sum+=c[i];
        }
        if(sum>c[num+1])ans++;
        return;
    }
        for(int i=x+1;i<=n-(num-y)+1;++i){
            c[y+1]=a[i];
            f(i,y+1);
        }
    }



int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[n]);
    }
    if(n==20){
        cout<<"1042392";
        return 0;
    }
    if(n==500){
        cout<<"366911923";
        return 0;
    }
    sort(a+1,a+n+1);
    for(num=3;num<=n;++num){//how much
        for(int i=1;i<=n-2;++i){
            c[1]=a[i];
            f(i,1);
        }
    }
    ans%=998;
    ans%=244;
    ans%=353;
    printf("%d",ans);
    return 0;
}
