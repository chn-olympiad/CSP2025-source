#include<bits/stdc++.h>
using namespace std;
int a[3][100010];
int biggest(int x){
    int mx=max(a[0][x],max(a[1][x],a[2][x]));
    if(a[0][x]==mx)return 0;
    if(a[1][x]==mx)return 1;
    return 2;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int num0=0,num1=0,num2=0,mx=0,ans=0,bj[n]={-1},small[n]={0},zz=0;
        for(int i=0;i<n;i++)cin>>a[0][i]>>a[1][i]>>a[2][i];
        for(int i=0;i<n;i++){
            int wei=biggest(i);
            if(wei==0)num0++;
            else if(wei==1)num1++;
            else num2++;
            ans+=a[wei][i];
            bj[i]=wei;
        }
        if(num1>n/2){
            for(int i=0;i<n;i++){
                swap(a[0][i],a[1][i]);
                if(bj[i]==1)bj[i]=0;
                else if(bj[i]==0)bj[i]=1;
            }
            swap(num0,num1);
        }
        else if(num2>n/2){
            for(int i=0;i<n;i++){
                swap(a[0][i],a[2][i]);
                if(bj[i]==2)bj[i]=0;
                else if(bj[i]==0)bj[i]=2;
            }
            swap(num0,num2);
        }
        if(num0>n/2){
            for(int i=0;i<n;i++){
                if(bj[i]==0){
                    small[zz]=a[0][i]-max(a[1][i],a[2][i]);
                    zz++;
                }
            }
            sort(small,small+zz);
            for(int i=0;i<num0-n/2;i++)ans-=small[i];
        }
        cout<<ans<<'\n';
    }
    return 0;
}
