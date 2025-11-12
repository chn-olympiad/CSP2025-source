#include <iostream>

using namespace std;
int n,t,s[4],mb[100001];
struct node{
    int a,b,c,abch,bcch;
}q[100001],p[100001];
bool cmp(node a,node b){
    if(a.abch!=b.abch)return a.abch>b.abch;
    else return a.bcch>b.bcch;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int manyi=0; 
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>q[i].a>>q[i].b>>q[i].c;
            if(max(q[i].a,max(q[i].b,q[i].c))==q[i].a){
                p[i].a=1;
                if(max(q[i].b,q[i].c)==q[i].b)p[i].b=2,p[i].c=3,p[i].abch=q[i].a-q[i].b,p[i].bcch=q[i].b-q[i].c;
                if(max(q[i].b,q[i].c)==q[i].b)p[i].b=3,p[i].c=2,p[i].abch=q[i].a-q[i].c,p[i].bcch=q[i].c-q[i].b;
            }else if(max(q[i].a,max(q[i].b,q[i].c))==q[i].b){
                p[i].a=2;
                if(max(q[i].a,q[i].c)==q[i].a)p[i].b=1,p[i].c=3,p[i].abch=q[i].b-q[i].a,p[i].bcch=q[i].a-q[i].c;
                if(max(q[i].a,q[i].c)==q[i].c)p[i].b=3,p[i].c=1,p[i].abch=q[i].b-q[i].c,p[i].bcch=q[i].c-q[i].a;
            }else{
                p[i].a=3;
                if(max(q[i].a,q[i].b)==q[i].a)p[i].b=1,p[i].c=2,p[i].abch=q[i].c-q[i].a,p[i].bcch=q[i].a-q[i].b;
                if(max(q[i].a,q[i].b)==q[i].b)p[i].b=2,p[i].c=1,p[i].abch=q[i].c-q[i].b,p[i].bcch=q[i].b-q[i].a;
            }
        }
        sort(p+1,p+1+n,cmp);
        for(int i=1;i<=n;i++){
            if(s[p[i].a]<=n/2){
                s[p[i].a]++;
                if(p[i].a==1)manyi+=q[i].a;
                if(p[i].a==2)manyi+=q[i].b;
                if(p[i].a==3)manyi+=q[i].c;
            }else{
                s[p[i].b]++;
                if(p[i].b==1)manyi+=q[i].a;
                if(p[i].b==2)manyi+=q[i].b;
                if(p[i].b==3)manyi+=q[i].c;
            }
        }
        cout<<manyi<<"\n";
    }
    return 0;
}
