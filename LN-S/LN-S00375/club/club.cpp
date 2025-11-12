#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int t;
int n,a[N][4],s[N][4],ss[N],s2[N],s3[N];
bool cmp(int a,int b){
    return a>b;
}
int f(){
    int cnt=0,flag=0,dyw=0;
    int idx[4];
    for(int i=1;i<=n;i++){
        if(s[i][1]>s[i+1][1]+s[i][2]&&idx[1]<n/2&&(s[i+1][2]==0&&s[i+1][3]==0)&&flag==0){
            idx[1]++;
            flag=1;
            cnt+=s[i][1];
        }
        if(s[i][1]<(s[i+1][1]+s[i][2])&&idx[1]<n/2&&idx[2]<n/2&&(s[i+1][2]==0&&s[i+1][3]==0)&&flag==0){
            idx[1]++;
            idx[2]++;
            flag=1;

            cnt+=s[i][2]+s[i+1][1];
            dyw+=2;
            if(dyw==n) return cnt;
        }
        if(s[i][1]>s[i+1][1]+s[i][3]&&idx[1]<n/2&&flag==0){
            idx[1]++;
            cnt+=s[i][1];
            flag=1;
            dyw++;
            if(dyw==n) return cnt;
        }
        if(s[i][1]<s[i+1][1]+s[i][3]&&idx[1]<n/2&&idx[3]<n/2&&(s[i+1][2]==0&&s[i+1][3]==0)&&flag==0){
            idx[1]++;
            flag=1;
            idx[3]++;
            cnt+=s[i][3]+s[i+1][1];
            dyw+=2;
            if(dyw==n) return cnt;
        }
        if(idx[1]<n/2){
            idx[1]++;
            int ll=1;
            while(ss[ll]==-1){
                ll++;
            }
            cnt+=ss[ll];
            ss[ll]=-1;
            dyw++;
            if(dyw==n) return cnt;
        }else if(idx[2]<n/2){
            idx[2]++;
            int ll=1;
            while(s2[ll]==-1){
                ll++;
            }
            cnt+=s2[ll];
            s2[ll]=-1;
            dyw++;
            if(dyw==n) return cnt;
        }else if(idx[3]<n/2){
            idx[3]++;
            int ll=1;
            while(s3[ll]==-1){
                ll++;
            }
            cnt+=s3[ll];
            s3[ll]=-1;
            dyw++;
            if(dyw==n) return cnt;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t!=0){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
            s[i][1]=max(a[i][1],max(a[i][2],a[i][3]));
            s[i][3]=min(a[i][1],min(a[i][2],a[i][3]));
            s[i][2]=a[i][1]+a[i][2]+a[i][3]-s[i][1]-s[i][3];
            ss[i]=s[i][1];
            s2[i]=s[i][2];
            s3[i]=s[i][3];
        }
        sort(ss+1,ss+1+n,cmp);
        sort(s2+1,s2+1+n,cmp);
        sort(s3+1,s3+1+n,cmp);
        cout<<f()<<endl;
        t--;
    }
    return 0;
}
















