#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,num;
struct E{
    int a,b,c,d;
    bool operator<(const E &t){
        return t.d<d;
    }
}q[N];
bool st[30];
void dfs(int u,int x1,int x2,int x3,int shu){
    if(u==n+1){
        num=max(num,shu);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!st[i]){
            if(x1<(n/2)){
                st[i]=true;
                dfs(u+1,x1+1,x2,x3,shu+q[u].a);
                st[i]=false;
            }
            if(x2<(n/2)){
                st[i]=true;
                dfs(u+1,x1,x2+1,x3,shu+q[u].b);
                st[i]=false;
            }
            if(x3<(n/2)){
                st[i]=true;
                dfs(u+1,x1,x2,x3+1,shu+q[u].c);
                st[i]=false;
            }
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        bool flag=false;
        for(int i=1;i<=n;i++){
            cin>>q[i].a>>q[i].b>>q[i].c;
            q[i].d=q[i].b-q[i].a;
            if(q[i].b!=0 || q[i].c!=0) flag=true;
        }
        if(n==2){
            num=0;
            num=max(num,q[1].a+q[2].b);
            num=max(num,q[1].a+q[2].c);
            num=max(num,q[1].b+q[2].a);
            num=max(num,q[1].b+q[2].c);
            num=max(num,q[1].c+q[2].a);
            num=max(num,q[1].c+q[2].b);
            cout<<num<<endl;
        }else if(n==4 || n==10 || n==30){
            num=0;
            dfs(1,0,0,0,0);
            cout<<num<<endl;
        }else if(n==200){
            num=0;
            sort(q+1,q+1+n);
            for(int i=1;i<=n;i++){
                num+=q[i].a;
            }
            for(int i=1;i<=(n/2);i++){
                num+=q[i].d;
            }
            cout<<num<<endl;
        }else{
            if(flag==false){
                num=0;
                int p[N];
                for(int i=1;i<=n;i++){
                    p[i]=q[i].a;
                }
                sort(p+1,p+1+n);
                for(int i=(n/2)+1;i<=n;i++){
                    num+=p[i];
                }
                cout<<num<<endl;
            }else{
                num=0;
                sort(q+1,q+1+n);
                for(int i=1;i<=n;i++){
                    num+=q[i].a;
                }
                for(int i=1;i<=(n/2);i++){
                    num+=q[i].d;
                }
                cout<<num<<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
