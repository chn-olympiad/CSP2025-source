#include<bits/stdc++.h>
using namespace std;
int _,n,o2,o3,kkk;
struct node{
    int x,y,z;
}a[100000];
int dfs(int _1,int _2,int _3,int now,int len){
    if(now>n)return len;
    int ans=0;
    if(_1<n/2)ans=max(ans,dfs(_1+1,_2,_3,now+1,len+a[now].x));
    if(_2<n/2)ans=max(ans,dfs(_1,_2+1,_3,now+1,len+a[now].y));
    if(_3<n/2)ans=max(ans,dfs(_1,_2,_3+1,now+1,len+a[now].z));
    return ans;
}
void d(){
    node dp[205][105];kkk=0;memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        dp[i][1].x=a[i].x;
        dp[i][1].y=a[i].y;
        dp[i][1].z=a[i].z;
        if(i<=n/2){
            dp[i][i].x=dp[i-1][i-1].x+a[i].x;
            dp[i][i].y=dp[i-1][i-1].y+a[i].y;
            dp[i][i].z=dp[i-1][i-1].z+a[i].z;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=2;j<=min(i,n/2);j++){
            for(int k=j;k<i;k++){
                dp[i][j].x=max(dp[i][j].x,dp[k][j-1].x);
                dp[i][j].y=max(dp[i][j].y,dp[k][j-1].y);
                dp[i][j].z=max(dp[i][j].z,dp[k][j-1].z);
            }
            dp[i][j].x+=a[i].x;
            dp[i][j].y+=a[i].y;
            dp[i][j].z+=a[i].z;
        }
    }
    for(int j=1;j<=n/2;j++){
        kkk=max(max(kkk,dp[n][j].x),max(dp[n][j].y,dp[n][j].z));
    }
    cout<<kkk<<"\n";
}
bool cmp1(node xx,node yy){return xx.x>yy.x;}
bool cmp2(node xx,node yy){
    if(xx.x!=yy.x)return xx.x>yy.x;
    else return xx.y>yy.y;
}
void work1(){
    sort(a+1,a+n+1,cmp1);int sum=0;
    for(int i=1;i<=n/2;i++)sum+=a[i].x;
    cout<<sum<<"\n";
}
void work2(){
    sort(a+1,a+n+1,cmp2);
    int num1=0,num2=0,sum1=0,sum2=0;
    for(int i=1;i<=n;i++){
        if(a[i].x!=a[i].y){
            if(a[i].x>a[i].y&&num1<n/2||num2==n/2){
                num1++;
                sum1+=a[i].x;
            }else if(a[i].y>a[i].x&&num2<n/2||num1==n/2){
                num2++;
                sum2+=a[i].y;
            }
        }else{
            if(num1<num2){
                num1++;
                sum1+=a[i].x;
            }else{
                num2++;
                sum2+=a[i].y;
            }
        }
    }
    cout<<sum1+sum2<<"\n";
}
void toilet(){
    cin>>n;o2=o3=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>a[i].z;
        if(!a[i].y)o2++;
        if(!a[i].z)o3++;
    }
    if(n<=10)cout<<dfs(0,0,0,0,0)<<"\n";
    else if(o3==n){
        if(o2==n)work1();
        else work2();
    }else if(n<=200)d();
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>_;
    while(_--)toilet();
    fclose(stdin);fclose(stdout);
    return 0;
}
