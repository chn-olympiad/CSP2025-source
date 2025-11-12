#include <bits/stdc++.h>
using namespace std;

int n,m,s1,ans1=1,ans2=1,b=1;
int s[110];

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>s[i];
    }
    s1=s[1];
    sort(s+1,s+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(s[i]==s1){
            cout<<ans1<<" "<<ans2<<endl;
            return 0;
        }
        ans2+=b;
        if(ans2>n){
            ans1++;
            ans2--;
            b=-1;
        }
        if(ans2<1){
            ans1++;
            ans2++;
            b=1;
        }
    }
    return 0;
}
