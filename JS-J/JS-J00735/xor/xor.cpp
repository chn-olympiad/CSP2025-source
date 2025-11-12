#include<bits/stdc++.h>
using namespace std;
int a[500100],sum[500101],b[1100045];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    // cout<<"s:"<<sum[1]<<" "<<sum[2]<<" "<<sum[3]<<" "<<sum[4]<<"\n";
    memset(b,-1,sizeof(b));
    int s1=0,cnt=0;
    b[0]=0;
    for(int i=1;i<=n;i++){   //i refers to the pos of last integar
        
        if(cnt==0){
            if(b[sum[i]^k]==cnt){
                cnt++;
                s1=sum[i];
            }
        }
        else{
            if(b[sum[i]^s1]==cnt){
                cnt++;
                s1=sum[i];
            }
        }
        int s3=sum[i]^s1^k;
        b[s3]=cnt;
        // cout<<i<<" "<<cnt<<"\n";
        // cout<<(sum[i]^s1^k)<<"\n";
        // cout<<"b:"<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<b[4]<<"\n";
    }
    cout<<cnt;
}