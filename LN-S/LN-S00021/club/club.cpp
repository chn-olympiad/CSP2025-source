#include<bits/stdc++.h>
using namespace std;
int a[100010][4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        priority_queue<int> q1,q2,q3;
        int n,x=0,y=0,z=0;
        long long ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
                x++;
                ans+=a[i][1];
                q1.push(-(a[i][1]-max(a[i][2],a[i][3])));
            }else  if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
                y++;
                ans+=a[i][2];
                q2.push(-(a[i][2]-max(a[i][1],a[i][3])));
            }else{
                z++;
                ans+=a[i][3];
                q3.push(-(a[i][3]-max(a[i][1],a[i][2])));
            }
        }
        if(x>n/2){
            while(q1.size()>n/2){
                ans-=-q1.top();
                q1.pop();
            }
        }else  if(y>n/2){
            while(q2.size()>n/2){
                ans-=-q2.top();
                q2.pop();
            }
        }else  if(z>n/2){
            while(q3.size()>n/2){
                ans-=-q3.top();
                q3.pop();
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
