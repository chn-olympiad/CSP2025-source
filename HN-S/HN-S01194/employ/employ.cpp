#include<bits/stdc++.h>
using namespace std;
int n,m,sum,cut;
long long ans;
string s;
int a[505];
bool b[505];
void dfs(int x){
    if(x==n+1){
        if(sum>=m){
            ans++;
        }
        //cout<<sum<<"\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(!b[i]){
            if(a[i]<=cut || s[x-1]=='0'){
                cut++;
                b[i]=1;
                dfs(x+1);
                b[i]=0;
                cut--;
            }
            else{
                sum++;
                b[i]=1;
                dfs(x+1);
                b[i]=0;
                sum--;
            }
        }
    }
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1);
	cout<<ans%998244353;
	return 0;
}

