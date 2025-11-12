#include<iostream>
using namespace std;
const int N=500005;
struct node{
    int l,r;
}p[N];
int a[N]={0},s[N]={0};
bool check(int l2,int r2,int ans,int n){
    int l1=p[ans].l;
    int r1=p[ans].r;
    for(int i=1;i<=n;i++){
        if(l1<=i && i<=r1 && l2<=i && i<=r2){
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(ans==0){
                if(i==j){
                    if(a[i]==k){
                        p[ans+1].l=i;
                        p[ans+1].r=j;
                        ans++;
                    }
                }
                else if(s[j]^a[i-1]==k){
                    p[ans+1].l=i;
                    p[ans+1].r=j;
                    ans++;
                }
            }
            else if(check(i,j,ans,n)){
                continue;
            }
            else if(i==j){
                if(a[i]==k){
                    p[ans+1].l=i;
                    p[ans+1].r=j;
                    ans++;
                }
            }
            else if(s[j]^a[i-1]==k){
                p[ans+1].l=i;
                p[ans+1].r=j;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
