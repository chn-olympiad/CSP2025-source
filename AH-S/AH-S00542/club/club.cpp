#include<bits/stdc++.h>
using namespace std;
int T;
struct node{
    int a,b,c;
}shu[100005];
bool cmp1(node shu1,node shu2){
    return shu1.a>shu2.a;
}
int mshuin(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        bool f=1;
        int cnt=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>shu[i].a>>shu[i].b>>shu[i].c;
            if(shu[i].a!=0){
                f=0;
            }
        }
        if(f){
            sort(shu+1,shu+n+1,cmp1);
            for(int i=1;i<=n/2;i++) cnt+=shu[i].a;
        }else{
            sort(shu+1,shu+n+1,cmp1);
            for(int i=1;i<=n;i++){
                if(i<=n/2) cnt+=shu[i].a;
                else cnt+=shu[i].b;
            }

        }cout<<cnt<<endl;
    }
    return 0;
}
