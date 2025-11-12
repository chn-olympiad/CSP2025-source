#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node
{
    int st,nd,rd,c;
};
node a[N];
int m[3];
bool cmp1(node x,node y)
{
    return x.c<y.c;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        m[1]=0;
        m[2]=0;
        int n,num=0,ans=0;
        bool flag=1;
        cin>>n;
        int k=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i].st>>a[i].nd>>a[i].rd;
            if(a[i].rd!=0) flag=0;
            if(a[i].st>=a[i].nd) m[1]++,num+=a[i].st,a[i].c=a[i].st-a[i].nd;
            if(a[i].nd>a[i].st) m[2]++,num+=a[i].nd,a[i].c=a[i].nd-a[i].st;
            ans+=max(a[i].st,max(a[i].nd,a[i].rd));
            //cout<<a[i].c<<endl;
        }
        //cout<<m[1]<<" "<<m[2]<<endl;
        sort(a+1,a+1+n,cmp1);
        if(flag==0){
            cout<<ans<<endl;
            continue;
        }
        else if(m[1]<=k&&m[2]<=k) cout<<num<<endl;
        else if(m[1]>k){
            for(int i=1;i<=n;i++){

                if(a[i].st>=a[i].nd)num-=a[i].c,m[1]--;
                if(m[1]==k){
                    cout<<num<<endl;
                    break;
                }
            }
        }
       else if(m[2]>k){
            for(int i=1;i<=n;i++){
                if(a[i].st<a[i].nd)num-=a[i].c,m[2]--;
                if(m[2]==k){
                    cout<<num<<endl;
                    break;
                }
            }
        }

    }
    return 0;
}
