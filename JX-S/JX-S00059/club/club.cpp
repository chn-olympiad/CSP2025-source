#include<bits/stdc++.h>
using namespace std;

int n;
int a[100005],b[100004],c[100005];

bool cmp(int x,int y){
    return x>y;
}

int ans=0;
int sum1,sum2,sum3;
bool f1,f2,f3;
void dfs(int i,int sum){
    ans=max(ans,sum);
    if(i>n)return;

    if(sum1<n/2 && f1==false){
        sum1++;
        dfs(i+1,sum+a[i]);
        sum1--;
    }
    if(sum2<n/2 && f2==false){
        sum2++;
        dfs(i+1,sum+b[i]);
        sum2--;
    }
    if(sum3<n/2 && f3==false){
        sum3++;
        dfs(i+1,sum+c[i]);
        sum3--;
    }
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        ans=0;
        sum1=sum2=sum3=0;
        f1=f2=f3=true;
        f1=false;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(a[i])f1=false;
            if(b[i])f2=false;
            if(c[i])f3=false;
        }
        if(f1==false&&f2==true&&f3==true)sort(a+1,a+n+1,cmp);
        if(f1==true&&f2==false&&f3==true)sort(a+1,a+n+1,cmp);
        if(f1==true&&f2==true&&f3==false)sort(a+1,a+n+1,cmp);

        dfs(1,0);
        cout<<ans<<'\n';
    }
    return 0;
}
