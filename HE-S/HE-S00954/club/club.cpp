#include<bits/stdc++.h>
using namespace std;
struct node{
    int mx;
    int a,b,c;
} s[100010];
int tot[10];
#define clearArr(tot)\
    for(auto &i:tot){\
        i=0;\
    }

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,ret=0;
        clearArr(tot);
        scanf("%d",&n);
        int maxNum=n/2;
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
            s[i].mx=max(s[i].a,max(s[i].c,s[i].b));
        }sort(s,s+n,[](node x,node y){return x.mx>y.mx;});
        for(int i=0;i<n;i++){
            if(s[i].a==s[i].mx&&tot[1]<maxNum){
                (ret+=s[i].a),(++tot[1]);
            }else if(s[i].b>=s[i].c&&tot[2]<maxNum){
                (ret+=s[i].b),(++tot[2]);
            }else{
                (ret+=s[i].c),(++tot[3]);
            }
        }printf("%d\n",ret);
    }

    return 0;
}