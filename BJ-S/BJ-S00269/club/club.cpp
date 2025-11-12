#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct stt{
 int x,y,z;
}a[200005];
bool cmp(stt p,stt q){
    int pf=2*max(p.x,max(p.y,p.z))-p.x-p.y-p.z+min(p.x,min(p.y,p.z));
    int qf=2*max(q.x,max(q.y,q.z))-q.x-q.y-q.z+min(q.x,min(q.y,q.z));
    return pf>=qf;
}

void slove(){
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y>>a[i].z;
    sort(a+1,a+1+n,cmp);
    ll ans=0,X=0,Y=0,Z=0;
    for(int i=1;i<=n;i++){
        if(a[i].x>=max(a[i].y,a[i].z)){
            if(X<n/2)
                ans+=a[i].x,X++;
            else{
                if(a[i].y>a[i].z)
                    ans+=a[i].y,Y++;
                else
                    ans+=a[i].z,Z++;
            }
        }
        else if(a[i].y>=max(a[i].x,a[i].z)){
            if(Y<n/2)
                ans+=a[i].y,Y++;
            else{
                if(a[i].x>a[i].z)
                    ans+=a[i].x,X++;
                else
                    ans+=a[i].z,Z++;
            }
        }
        else{
            if(Z<n/2)
                ans+=a[i].z,Z++;
            else{
                if(a[i].y>a[i].x)
                    ans+=a[i].y,Y++;
                else
                    ans+=a[i].x,X++;
            }
        }
    }
    cout<<ans;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
        slove(),cout<<'\n';
}
//Thanks my god!!!!!!