#include<bits/stdc++.h>
using namespace std;
int T;
int n,mx=0;
int bo[100005];
bool tong[100005];
//Ren5Jie4Di4Ling5%
struct node{
    int a,b,c;
}da[100005];
struct bel{
    int value,belong,belong2;
}t[200005];
bool cmp(node x,node y){
    return x.a>y.a;
}
bool cmp2(node x,node y){
    return x.b>y.b;
}
bool cmp3(bel x,bel y){
    return x.value>y.value;
}
void dfs(int x,int a,int b,int c){
    if(x==n+1){
        int sum=0;
        for(int i=1;i<=n;i++){
            if(bo[i]==1){
                sum+=da[i].a;
            }
            if(bo[i]==2){
                sum+=da[i].b;
            }
            if(bo[i]==3){
                sum+=da[i].c;
            }
        }
        mx=max(mx,sum);
        return ;
    }
    if(a+1<=n/2&&b<=n/2&&c<=n/2){
        bo[x+1]=1;
        dfs(x+1,a+1,b,c);
    }
    if(a<=n/2&&b+1<=n/2&&c<=n/2){
        bo[x+1]=2;
        dfs(x+1,a,b+1,c);
    }
    if(a<=n/2&&b<=n/2&&c+1<=n/2){
        bo[x+1]=3;
        dfs(x+1,a,b,c+1);
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        mx=0;
        bool fa=1,fb=1;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>da[i].a>>da[i].b>>da[i].c;
            if(da[i].b!=0)fa=0;
            if(da[i].c!=0)fa=fb=0;
        }
        if(fa){
            sort(da+1,da+1+n,cmp);
            int sum=0;
            for(int i=n;i>=n/2+1;i--){
                sum+=da[i].a;
            }
            cout<<sum<<endl;
        }else if(fb){
            /*
            start
            bool t[100005];
            for(int i=1;i<=n;i++){
                t[i]=0;
            }
            int sum=0,sum2=0;
            sort(da+1,da+1+n,cmp);
            for(int i=1;i<=n/2;i++){
                sum+=da[i].a;
            }
            for(int i=n/2+1;i<=n;i++){
                sum+=da[i].b;
            }
            sort(da+1,da+1+n,cmp2);
            for(int i=1;i<=n/2;i++){
                sum2+=da[i].b;
            }
            for(int i=n/2+1;i<=n;i++){
                sum2+=da[i].a;
            }
            cout<<max(sum,sum2)<<endl;
            end
            */
            int sum2=0;
            for(int i=1;i<=n;i++){
                tong[i]=0;
            }
            int awork=0,bwork=0;
            for(int i=1;i<=n;i++){
                t[2*i-1].value=da[i].a,t[2*i].value=da[i].b;
                t[2*i-1].belong=i,t[2*i].belong=i;
                t[2*i-1].belong2=1,t[2*i].belong2=2;
            }
            sort(t+1,t+2*n+1,cmp3);
            /*for(int i=1;i<=2*n;i++){
                cout<<t[i].value<<" "<<t[i].belong<<endl;
            }
            cout<<endl;*/
            int summ=0;
            for(int i=1;i<=2*n;i++){
                if(tong[t[i].belong]==1){
                    continue;
                }else{
                    if(t[i].belong2==1&&awork<n/2){
                        sum2+=t[i].value;
                        tong[t[i].belong]=1;
                        summ++;
                        awork++;
                    }else if(t[i].belong2==2&&bwork<n/2){
                        sum2+=t[i].value;
                        tong[t[i].belong]=1;
                        summ++;
                        bwork++;
                    }
                }
                if(summ==n){
                    break;
                }
            }
            cout<<sum2<<endl;
        }else if(n<=30){
            dfs(0,0,0,0);
            cout<<mx<<endl;
        }else{
            int sum=0;
            for(int i=1;i<=n;i++){
                sum+=max(da[i].a,max(da[i].b,da[i].c));
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
