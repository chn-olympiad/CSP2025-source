#include<bits/stdc++.h>
using namespace std;
int MOD=998224353;
int n,m,a[505],ans;
int c[505];
string s;
int main(){
    freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        c[i]=s[i-1]-'0';
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(c[i]==1){
                ans++;
            }
            else{
                continue;
            }
        }
    }
    cout<<ans;
	fclose(stdin);
	fclose(stdout);
    return 0;
}