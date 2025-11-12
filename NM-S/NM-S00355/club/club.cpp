#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll f,s,t;
};
node a[100005];

bool cmp(node a,node b){
    return a.f>b.f;
}


ll mem[100005][4];
ll found;
void dfs(ll n,ll pos,ll sum,ll num1,ll num2,ll num3){

    if(num1>n/2||num2>n/2||num3>n/2) return;


    if(pos>n){
        if(sum<=found) return;
        found=sum;
        return;
    }


    if(num1+1<=n/2){
        mem[pos][num1]=sum;

        dfs(n,pos+1,sum+a[pos].f,num1+1,num2,num3);
    }
    if(num2+1<=n/2){
        mem[pos][num2]=sum;
        dfs(n,pos+1,sum+a[pos].s,num1,num2+1,num3);
    }
    if(num3+1<=n/2){
        mem[pos][num3]=sum;
        dfs(n,pos+1,sum+a[pos].t,num1,num2,num3+1);
    }

    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));
        memset(mem,-1,sizeof(mem));
        found=0;
        ll n;
        cin>>n;
        for(ll i=1;i<=n;i++){
            cin>>a[i].f>>a[i].s>>a[i].t;
        }
        int k=0;
        for(ll i=1;i<=n;i++){
            if(a[i].s!=0||a[i].t!=0) k++;
        }
        if(k==0){
            sort(a+1,a+1+n,cmp);
            for(int i=1;i<=n/2;i++){
                found+=a[i].f;
            }
        }

       else if(n<=10){
            dfs(n,1,0,0,0,0);
       }


        cout<<found<<'\n';



    }



    fclose(stdin);
    fclose(stdout);
    return 0;
}
