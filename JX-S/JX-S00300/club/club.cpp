#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=1e5+5;
long long a[5][N],cnt[5];
long long n;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin>>T;
    while(T--){
        priority_queue<long long>max1,max2,max3;
        cin>>n;
        long long ans=0;
        cnt[1]=cnt[2]=cnt[3]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%d",&a[j][i]);
            }
        }
        for(int i=1;i<=n;i++){
            int maxx=max(a[1][i],max(a[2][i],a[3][i]));
            if(a[1][i]==maxx){
                cnt[1]++;
                ans+=a[1][i];
            }
            else if(a[2][i]==maxx){
                cnt[2]++;
                ans+=a[2][i];
            }
            else if(a[3][i]==maxx){
                cnt[3]++;
                ans+=a[3][i];
            }
            //3
            int flag=0;
            if(cnt[3]>n/2){
                long long m3=max3.top();
                if(a[3][i]+m3>max(a[1][i],a[2][i])){
                    ans+=m3;
                    max3.pop();
                }
                else{
                    flag=3;
                    ans-=a[3][i];
                    ans+=max(a[1][i],a[2][i]);
                }
                cnt[3]--;
            }
            //2
            else if(cnt[2]>n/2){
                long long m2=max2.top();
                if(a[2][i]+m2>max(a[1][i],a[3][i])){
                    ans+=m2;
                    max2.pop();
                }
                else{
                    flag=2;
                    ans-=a[2][i];
                    ans+=max(a[1][i],a[3][i]);
                }
                cnt[2]--;
            }
            //1
            else if(cnt[1]>n/2){
                long long m1=max1.top();
                if(a[1][i]+m1>max(a[2][i],a[3][i])){
                    ans+=m1;
                    max1.pop();
                }
                else{
                    flag=1;
                    ans-=a[1][i];
                    ans+=max(a[2][i],a[3][i]);
                }
                cnt[1]--;
            }
            if(flag!=1&&a[1][i]==maxx){
                max1.push(max(a[2][i]-a[1][i],a[3][i]-a[1][i]));
            }
            else if(flag!=2&&a[2][i]==maxx){
                max2.push(max(a[1][i]-a[2][i],a[3][i]-a[2][i]));
            }
            else if(flag!=3&&a[3][i]==maxx){
                max3.push(max(a[1][i]-a[3][i],a[2][i]-a[3][i]));
            }
        }
    cout<<ans<<endl;
    }
    return 0;
}
