#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int t,n,a[100005],b[100005],c[100005],p[5];
long long ans;
bool A=1,B=1;
long long cjsum[100005];
void dfs(int t,long long sum){
    if(t>n){
        ans=max(ans,sum);
        return ;
    }
    if(sum+cjsum[n]-cjsum[t-1]<=ans) return ;

    if(p[1]+1<=n/2){
        p[1]++;
        dfs(t+1,sum+a[t]);
        p[1]--;
    }

    if(p[2]+1<=n/2){
        p[2]++;
        dfs(t+1,sum+b[t]);
        p[2]--;
    }

    if(p[3]+1<=n/2){
        p[3]++;
        dfs(t+1,sum+c[t]);
        p[3]--;
    }
}
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int cnt=1;cnt<=t;cnt++){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(cnt==1){
                if(!(b[i]==0&&c[i]==0)) A=0;
                if(c[i]!=0) B=0;
            }
            cjsum[i]=cjsum[i-1]+max( max(a[i],b[i]),c[i] );
        }
        if(A){
           sort(a+1,a+n+1,cmp);
           for(int i=1;i<=n/2;i++){
                ans+=a[i];
           }
           cout<<ans;
        }else if(B){
            dfs(1,0);
            cout<<ans<<endl;
        }else{
            dfs(1,0);
            cout<<ans<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
return 0;
}
//Ren5Jie4Di4Ling5%
