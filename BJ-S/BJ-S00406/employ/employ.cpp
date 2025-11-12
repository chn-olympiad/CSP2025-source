#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string s;
int flag;
int c[555];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]!=0){
            flag++;
        }
    }
    if(flag>=m){
        int ans=1;
        for(int i=1;i<=n;i++){
            ans*=i;
        }
        cout<<ans%998244353;
    }
    else{
        cout<<0;
    }
	return 0;
}

