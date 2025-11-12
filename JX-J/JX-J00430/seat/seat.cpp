#include<bits/stdc++.h>
using namespace std;
#define o 100
int a[o];
int b[o];
int n,m;
bool cmp(int x,int y){
    if(x<y) return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

    cin>>n>>m;
    int s=n*m;
    for(int i=1;i<=s;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+s+1,cmp);
    int ans;
    for(int i=1;i<=s;i++){
        if(b[i]==a[1]){
            ans=i;
        }
    }
    cout<<ans/n<<" ";
    if(ans%n==0) cout<<n;
}
