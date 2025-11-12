#include <bits/stdc++.h>
using namespace std;
int t,n,ans=0;
bool sum[10001];
int b[10001]={};
struct node{
   int x;
   int y;
   int z;
}a[10001]={};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    for(int i=0;i<10001;i++){
    sum[i]=false;
    }
    cin>>t;
    int max2=0,d1=0;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>a[j].x>>a[j].y>>a[j].z;
            int max1=0,first=0,second=0,third=0,d=0;
            if(first>n/2 || second>n/2 || third>n/2){
                if(max1>max2){
                    max1=max2;
                    d=d1;
                }
            }
            if(a[j].x>max1 && !sum[j] && first<=n/2){
                max1=a[j].x;
                d=j;
            }
            else if(a[j].y>max1 && !sum[j] && second<=n/2){
                max1=a[j].y;
                d=j;
            }
            else if(a[j].z>max1 && !sum[j] && third<=n/2){
                max1=a[j].z;
                d=j;
            }
            max2=max1;
            d1=d;
            sum[d]=true;
            if(max1==a[d].x){
                first++;
                b[d]=1;
            }
            else if(max1==a[d].y){
                second++;
                b[d]=2;
            }
            else if(max1==a[d].z){
                third++;
                b[d]=3;
            }
            d=0;
            max1=0;
        }
        for(int i=0;i<n;i++){
            if(sum[i]==true){
                if(b[i]==1){
                    ans+=a[i].x;
                }
                else if(b[i]==2){
                    ans+=a[i].y;
                }
                else if(b[i]==3){
                    ans+=a[i].z;
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
