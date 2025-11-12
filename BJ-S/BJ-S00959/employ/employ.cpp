#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","r",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=0;
    if(m==1||(s[s.size()-1]==0&&s[s.size()-2]==0&&s[s.size()-3]==0&&s[s.size()-4]==0)){
        while(n--){
            ans+=n;
        }
        cout<<ans+n;
    }else{

    }
    return 0;
}
