#include<bits/stdc++.h>
using namespace std;
const int dd=1e5+5;
int t,n,a[dd][4],s,ss,b[dd];
long long ans,dp[dd][4],ddp[dd];
void sou(int wei,int i,int j,int k,long long sum){
    if(i+j+k==n&&wei==n+1){
        ans=max(ans,sum);
        return;
    }
    if(i<n/2) sou(wei+1,i+1,j,k,sum+a[wei][1]);
    if(j<n/2) sou(wei+1,i,j+1,k,sum+a[wei][2]);
    if(k<n/2) sou(wei+1,i,j,k+1,sum+a[wei][3]);
}
void syc(){
    //cout<<"I am Grade Three in hign school."<<endl;
    //cout<<"It may be my last time join in this exam."<<endl;
    //cout<<"And I do not have any idea about the questions."<<endl;
    //cout<<"The only way for me is studying,not take part in this exam"<<endl;
    //cout<<"With 218 days left for 'The Great Exam',I wish I can get 660.Also,I want to get the 50 position in the mid-term exam"<<endl;
    //cout<<"Wishing all the best for you"<<endl;
    //cout<<"Lynx-Brooks"<<endl;
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin>>t;
for(int i=1;i<=t;i++){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        dp[i][1]=0,dp[i][2]=0,dp[i][3]=0,b[i]=0;
        if(a[i][2]==0) s++;
        if(a[i][3]==0) ss++;
    }
    if(s==n&&ss==n){
        for(int i=1;i<=n;i++) b[i]=a[i][1];
        sort(b+1,b+1+n);
        for(int i=n;i>n/2;i--) ans+=b[i];
        cout<<ans<<endl;
        break;
    }
    else if(ss==n){
        syc();
        break;
    }
    //for(int i=1;i<=n;i++){
    //    for(int j=m;j>=b[i];j--){
    //        dp[j]=max(dp[j],dp[j-b[i]]+a[i]);
    //    }
    //}
    sou(1,0,0,0,0);
    //for(int i=1;i<=n;i++){
    //    for(int j=1;j<=3;j++){

    //    }
    //}
    cout<<ans<<endl;
    ans=0;
}
return 0;
}
