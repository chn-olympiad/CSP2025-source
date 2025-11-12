#include <bits/stdc++.h>
using namespace std;
string s;
int j=0;
long long ans=0;
int a[1000005];
bool v[1000005];
void dfs(int p,long long sum){
	if(p==j+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=j;i++){
		if(!v[i]){
			v[i]=1;
			dfs(p+1,sum*10+a[i]);
			v[i]=0;
		}
	}
	return;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++j]=s[i]-'0';
        }
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
