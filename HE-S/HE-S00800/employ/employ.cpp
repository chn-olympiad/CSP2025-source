#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1,cnt,cnt1;
int a[505];     
string s1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s1;
	cnt1=n;
	for(int i=0;i<n;i++)cnt++;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)cnt1--;
	}
	if(cnt<m||cnt1<m)cout<<0;
	else if(cnt==n){
	    for(int i=1;i<=n;i++){
		    ans*=i;
		    ans%=998244353;
	    }
	    cout<<ans;
	    return 0;
	}
	return 0;
}
// q.7
//~l2
//ÈË½ÜµØÁé
//5 4 4 5

