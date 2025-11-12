#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[100005][4];
int mx[100005]={-1};
int pos[100005];
int postot[4]={0};
int delta[100005];
int counter=1;
int realdelta[100005];
ll ans=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,mid=-1;
        bool flag=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            for(int j=1;j<=3;j++)
                if(a[i][j]>mx[i]){
                    mx[i]=a[i][j];
                    pos[i]=j;
                }
            postot[pos[i]]++;
            for(int j=1;j<=3;j++)
                if(a[i][j]>mid&&a[i][j]<mx[i])
                    mid=a[i][j];
            delta[i]=mx[i]-mid;
            mid=-1;
        }
        for(int j=1;j<=n;j++)ans+=mx[j];
        for(int j=1;j<=3;j++){
            if(postot[j]>n/2){
                for(int i=1;i<=n;i++)
                    if(pos[i]==j){
                        realdelta[counter]=delta[i];
                        counter++;
                    }
                sort(realdelta+1,realdelta+counter);
                for(int i=1;i<=postot[j]-n/2;i++)
                    ans-=realdelta[i];
            }
        }
        cout<<ans<<endl;
        ans=0;
        counter=1;
        for(int i=1;i<=n;i++){
            mx[i]=-1;pos[i]=0;delta[i]=0;
            realdelta[i]=0;
            for(int j=1;j<=3;j++)a[i][j]=0;
        }
        postot[1]=0;
        postot[2]=0;
        postot[3]=0;
    }
    return 0;
}
