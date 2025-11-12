#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100010],b[100010],c[100010],ans=0;
int aptr,bptr,cptr;
struct node{
    int a,b,c;
}q;

int compare(node q){
    if(q.a>q.b&&q.a>q.c){
        if(aptr+1>n/2)return compare({-1,q.b,q.c});
        else return 0;
    }else if(q.b>q.a&&q.b>q.c){
        if(bptr+1>n/2)return compare({q.a,-1,q.c});
        else return 1;
    }else{
        if(cptr+1>n/2)return compare({q.a,q.b,-1});
        else return 2;
    }
}
int select(node q){
    int choice=compare(q);
    if(choice==0)a[++aptr]=q.a;
    else if(choice==1)b[++bptr]=q.b;
    else c[++cptr]=q.c;
    return choice;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int ans=0;
        aptr=0,bptr=0,cptr=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>q.a>>q.b>>q.c;
            select(q);
            //cout<<i<<' '<<select(q)<<endl;
        }
        sort(a+1,a+aptr+1,greater<int>());
        sort(b+1,b+bptr+1,greater<int>());
        sort(c+1,c+cptr+1,greater<int>());
        for(int i=1;i<=aptr;i++){
            if(i>n/2)break;
            ans+=a[i];
        }
        for(int i=1;i<=bptr;i++){
            if(i>n/2)break;
            ans+=b[i];
        }
        for(int i=1;i<=cptr;i++){
            if(i>n/2)break;
            ans+=c[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
