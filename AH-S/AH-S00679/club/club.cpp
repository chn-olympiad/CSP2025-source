#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int s[100005];
int all=0;
int t,n;
struct node{
    int a1,a2,a3;
}a[100005];
bool cmp(node x,node y){
    return x.a1>y.a1;
}
bool cmp1(node x,node y){
    return x.a2>y.a2;
}
bool cmp2(node x,node y){
    return x.a3>y.a3;
}
void f(int pos,int sum,int ac,int bc,int cc){
    if(ac>n/2||bc>n/2||cc>n/2) return ;
    if(pos==n+1){
        all=max(all,sum);
        return ;
    }
    if(sum+s[n]-s[pos]<all) return ;
    f(pos+1,sum+a[pos+1].a1,ac+1,bc,cc);
    f(pos+1,sum+a[pos+1].a2,ac,bc+1,cc);
    f(pos+1,sum+a[pos+1].a3,ac,bc,cc+1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        bool flag=false,flag1=false,flag2=false;
        for(int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
            int ff=max(a[i].a1,max(a[i].a2,a[i].a3));
            s[i]=s[i-1]+ff;
            if(a[i].a2!=0||a[i].a3!=0){
                flag=true;
            }
            if(a[i].a1!=0||a[i].a3!=0){
                flag1=true;
            }
            if(a[i].a1!=0||a[i].a2!=0){
                flag2=true;
            }
        }
        if(!flag){
            sort(a+1,a+n+1,cmp);
            int ans=0;
            for(int i=1;i<=n/2;i++){
                ans+=a[i].a1;
            }
            cout<<ans<<endl;
        }else if(!flag1){
            //cout<<1<<endl;
            sort(a+1,a+n+1,cmp1);
            int ans=0;
            for(int i=1;i<=n/2;i++){
                ans+=a[i].a2;
            }
            cout<<ans<<endl;
        }else if(!flag2){
            //cout<<2<<endl;
            sort(a+1,a+n+1,cmp2);
            int ans=0;
            for(int i=1;i<=n/2;i++){
                ans+=a[i].a3;
            }
            cout<<ans<<endl;
        }else{
            all=0;
            f(0,0,0,0,0);
            cout<<all<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
