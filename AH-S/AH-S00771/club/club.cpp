#include <bits/stdc++.h>
using namespace std;
int t,anss;
int n,a[100005][5];
struct node{
    int ns1,ns2,maxn;
}dp[100005][3];
int dfs(int n1,int n2,int n3,int i,int ans){
    if(n1>(n/2)||n2>(n/2)||n3>(n/2))return -1;
    if(i==n+1){
        anss=max(anss,ans);
        /*
        b[i].n1n=0;
        b[i].n2n=0;
        b[i].n3n=0;
        cout<<n1<<" "<<n2<<" "<<n3<<" "<<ans<<endl;
        */
        return ans;
    }
    /*
    if(b[i].maxn!=0&&n1+b[i].n1n<=(n/2)&&n2+b[i].n2n<=(n/2)&&n3+b[i].n3n<=(n/2)){
        cout<<n1+b[i].n1n<<" "<<n2+b[i].n2n<<" "<<n3+b[i].n3n<<" "<<b[i].maxn+ans<<" A"<<endl;
        return b[i].maxn+ans;
    }
    */
    int pluso=0;
    /*node v;
    int ansi;*/
    for(int idx=1;idx<=3;idx++){
        if(idx==1){
            int temp=dfs(n1+1,n2,n3,i+1,ans+a[i][idx]);
            if(temp==-1)continue;
            else {
                if(temp>pluso){
                    pluso=temp;
                    /*
                    v.n1n=b[i+1].n1n+1;
                    v.n2n=b[i+1].n2n;
                    v.n3n=b[i+1].n3n;
                    ansi=idx;
                    */
                }
            }
        }
        if(idx==2){
            int temp=dfs(n1,n2+1,n3,i+1,ans+a[i][idx]);
            if(temp==-1)continue;
            else {
                if(temp>pluso){
                    pluso=temp;
                    /*
                    v.n1n=b[i+1].n1n;
                    v.n2n=b[i+1].n2n+1;
                    v.n3n=b[i+1].n3n;
                    ansi=idx;
                    */
                }
            }
        }
        if(idx==3){
            int temp=dfs(n1,n2,n3+1,i+1,ans+a[i][idx]);
            if(temp==-1)continue;
            else {
                if(temp>pluso){
                    pluso=temp;
                    /*
                    v.n1n=b[i+1].n1n;
                    v.n2n=b[i+1].n2n;
                    v.n3n=b[i+1].n3n+1;
                    ansi=idx;
                    */
                }
            }
        }
    }
    /*
    b[i].n1n=v.n1n;
    b[i].n2n=v.n2n;
    b[i].n3n=v.n3n;
    b[i].maxn=pluso-ans;
    */
    return pluso;
}
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        bool flag=true,flag2=true;
        int b[100005];
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            b[i]=a[i][1];
            if(a[i][2]!=0||a[i][3]!=0)flag=false;
            if(a[i][3]!=0)flag2=false;
        }
        if(flag){
            sort(b+1,b+1+n,cmp);
            int ansss=0;
            for(int i=1;i<=(n/2);i++){
                ansss+=b[i];
            }
            cout<<ansss<<endl;
        }
        else if(flag2){
            memset(dp,0,sizeof(dp));
            for(int i=1;i<=n;i++){
    //            cout<<dp[i-1][1].ns1<<" "<<dp[i-1][1].ns2<<" "<<dp[i-1][2].ns1<<" "<<dp[i-1][2].ns2<<" \n";
                if(dp[i-1][1].ns1+1<=(n/2)&&dp[i-1][2].ns1+1<=(n/2)){
                    if(dp[i-1][1].maxn>dp[i-1][2].maxn){
                        dp[i][1].ns1=dp[i-1][1].ns1+1;
                        dp[i][1].ns2=dp[i-1][1].ns2;
    //                    cout<<"A\n";
                    }
                    else {
                        dp[i][1].ns1=dp[i-1][2].ns1+1;
                        dp[i][1].ns2=dp[i-1][2].ns2;
      //                  cout<<"B\n";
                    }
                    dp[i][1].maxn=max(dp[i-1][1].maxn,dp[i-1][2].maxn)+a[i][1];
                }
                else if(dp[i-1][2].ns1+1<=(n/2)){
                    dp[i][1].maxn=dp[i-1][2].maxn+a[i][1];
                    dp[i][1].ns1=dp[i-1][2].ns1+1;
                    dp[i][1].ns2=dp[i-1][2].ns2;
        //            cout<<"C\n";
                }
                else if(dp[i-1][1].ns1+1<=(n/2)){
                    dp[i][1].maxn=dp[i-1][1].maxn+a[i][1];
                    dp[i][1].ns1=dp[i-1][1].ns1+1;
                    dp[i][1].ns2=dp[i-1][1].ns2;
          //          cout<<"D\n";
                }
                if(dp[i-1][2].ns2+1<=(n/2)&&dp[i-1][1].ns2+1<=(n/2)){
                    if(dp[i-1][1].maxn>=dp[i-1][2].maxn){
                        dp[i][2].ns1=dp[i-1][1].ns1;
                        dp[i][2].ns2=dp[i-1][1].ns2+1;
                    }
                    else {
                        dp[i][2].ns1=dp[i-1][2].ns1;
                        dp[i][2].ns2=dp[i-1][2].ns2+1;
                    }
                    dp[i][2].maxn=max(dp[i-1][1].maxn,dp[i-1][2].maxn)+a[i][2];
                }
                else if(dp[i-1][1].ns2+1<=(n/2)){
                    dp[i][2].maxn=dp[i-1][1].maxn+a[i][2];
                    dp[i][2].ns1=dp[i-1][1].ns1;
                    dp[i][2].ns2=dp[i-1][1].ns2+1;
                }
                else if(dp[i-1][2].ns2+1<=(n/2)){
                    dp[i][2].maxn=dp[i-1][2].maxn+a[i][2];
                    dp[i][2].ns1=dp[i-1][2].ns1;
                    dp[i][2].ns2=dp[i-1][2].ns2+1;
                }
            }
            cout<<max(dp[n][1].maxn,dp[n][2].maxn)<<endl;
        }
        else {
            cout<<dfs(0,0,0,1,0)<<endl;
        }
/*        for(int i=1;i<=n;i++){
            cout<<b[i].maxn<<" "<<b[i].n1n<<" "<<b[i].n2n<<" "<<b[i].n3n<<endl;
        }*/
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
