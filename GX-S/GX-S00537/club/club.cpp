#include<iostream>
#include<algorithm>
using namespace std;
const int maxx=1e5+5;
bool cmp(int a,int b){return a>b;}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int a[maxx],b,c;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i]>>b>>c;
        }
        sort(a,a+n,cmp);
        int ans=0,ca=0;
        for(int i=0;i<n;i++)
            if(ca+1<=n/2)
                ans+=a[i],ca++;
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
