#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+7;
int n;
int A[3][N];
int f[2][3][N];
int dp[207][207][207];
int p[N];
inline bool ChkA(){
    for(int i=1;i<=n;i++){
        if(max(A[1][i],A[2][i]))return 0;
    }return 1;
}inline bool Cmpa(int i,int j){
    return A[0][i]>A[0][j];
}inline bool ChkB(){
    for(int i=1;i<=n;i++){
        if(A[2][i])return 0;
    }return 1;
}inline bool Cmpb(int i,int j){
    return A[0][i]-A[1][i]>A[0][j]-A[1][j];
}

struct Node{
    int A,B,C;
}s[N];
inline bool cmp1(Node x,Node y){
    return x.A-x.B>y.A-y.B;
}inline bool cmp2(Node x,Node y){
    return x.C-x.A>y.C-y.A;
}inline bool cmp3(Node x,Node y){
    return x.C-x.B>y.C-y.B;
}
inline int pslv(){
    sort(s+1,s+n+1,cmp1);
    int p=-1;
    for(int i=0;i<n;i++){
        if(s[i+1].A<s[i+1].B){p=i;break;}
    }
    int Ans=0;
    for(int i=1;i<=n;i++)Ans+=max(s[i].A,s[i].B);
    if(p==-1)p=n;
    sort(s+1,s+p+1,cmp2);
    sort(s+p+1,s+n+1,cmp3);
    int l=1,r=n;
    if(p>n/2){
        while(p-l+1>n/2)Ans+=s[l].C-s[l].A,l++;
    }else if(n-p>n/2){
        while(r-p>n/2)Ans+=s[r].C-s[r].B,r--;
    }int Ch=n-(r-l+1);
    priority_queue<int> q;
    for(int i=l;i<=r;i++)q.push(s[i].C-(i<=p?s[i].A:s[i].B));
    while(!q.empty()&&Ch<n/2){
        int x=q.top();q.pop();
        if(x>0)Ch++,Ans+=x;
    }return Ans;
}
inline void slv(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>A[0][i]>>A[1][i]>>A[2][i];
    if(ChkA()){
        for(int i=1;i<=n;i++)p[i]=i;
        sort(p+1,p+n+1,Cmpa);
        int Ans=0;
        for(int i=1;i<=n/2;i++)Ans+=A[0][p[i]];
        cout<<Ans<<endl;
        return;
    }else if(ChkB()){
        for(int i=1;i<=n;i++)p[i]=i;
        sort(p+1,p+n+1,Cmpb);
        int Ans=0;
        for(int i=1;i<=n;i++){
            if(i<=n/2)Ans+=A[0][p[i]];
            else Ans+=A[1][p[i]];
        }cout<<Ans<<endl;
        return;
    }
    if(n<=200){
        for(int i=0;i<=n;i++)for(int j=0;j+i<=n;j++)for(int k=0;i+j+k<=n;k++)dp[i][j][k]=0;
        for(int i=1;i<=n;i++){
            for(int a=0;a<i;a++)for(int b=0;b+a<i;b++){
                int c=i-1-b-a;
                dp[a+1][b][c]=max(dp[a][b][c]+A[0][i],dp[a+1][b][c]);
                dp[a][b+1][c]=max(dp[a][b][c]+A[1][i],dp[a][b+1][c]);
                dp[a][b][c+1]=max(dp[a][b][c]+A[2][i],dp[a][b][c+1]);
            }
        }int Ans=0;
        for(int i=0;i<=n;i++)for(int j=0;i+j<=n;j++){
            int k=n-i-j;
            if(max(max(i,j),k)<=n/2)Ans=max(Ans,dp[i][j][k]);
        }cout<<Ans<<endl;
        return;
    }
    for(int i=1;i<=n;i++)s[i].A=A[0][i],s[i].B=A[1][i],s[i].C=A[2][i];
    int Ans=0;
    Ans=max(Ans,pslv());
    for(int i=1;i<=n;i++)swap(s[i].A,s[i].C);
    Ans=max(Ans,pslv());
    for(int i=1;i<=n;i++)swap(s[i].B,s[i].C);
    Ans=max(Ans,pslv());
    cout<<Ans<<endl;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;cin>>T;
    while(T--)slv();
}