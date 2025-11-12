#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c;
    int ma,mi,ch;
}k[114154];
int t,n,cnt,c1,c2,c3,cldl,cld,cz[114514];
bool cmp(int n,int k){
    return n<k;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>k[i].a>>k[i].b>>k[i].c;
            k[i].ma=max(k[i].a,max(k[i].b,k[i].c));
            k[i].mi=min(k[i].a,min(k[i].b,k[i].c));
            if(k[i].ma==k[i].a){
                    c1++;
                    k[i].ch=1;
            }
            else if(k[i].ma==k[i].b){
                    c2++;
                    k[i].ch=2;
            }
            else if(k[i].ma==k[i].c){
                    c3++;
                    k[i].ch=3;
            }
            cnt+=k[i].ma;
        }
        if(max(c1,max(c2,c3))<=n/2){
            cout<<cnt<<endl;
            cnt=0,c1=0,c2=0,c3=0,cldl=0,cld=0;
            continue;
        }
        if(max(c1,max(c2,c3))==c1){
                cldl=c1-n/2;
                cld=1;
        }
        if(max(c1,max(c2,c3))==c2){
                cldl=c2-n/2;
                cld=2;
        }
        if(max(c1,max(c2,c3))==c3){
                cldl=c3-n/2;
                cld=3;
        }
        int l=1;
        for(int i=1;i<=n;i++){
            if(k[i].ch==cld){
                cz[l]=k[i].ma-k[i].a-k[i].b-k[i].c+k[i].ma+k[i].mi;
                l++;
            }
        }
        sort(cz+1,cz+l,cmp);
        for(int i=1;i<=cldl;i++){
            cnt-=cz[i];
        }
        cout<<cnt<<endl;
        cnt=0,c1=0,c2=0,c3=0,cldl=0,cld=0;
    }
    return 0;
}
