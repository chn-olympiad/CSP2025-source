#include<bits/stdc++.h>
using namespace std;
long long n,m,man[505],ans=1;
string text;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>text;
	for(int i=1;i<=n;i++)cin>>man[i];
	long long s1=0;
	for(int i=0;i<text.size();i++){
		if(text[i]=='1')s1++;
	}
	for(int i=n;i>n-s1;i--){
		ans=(ans*i)%998244353;
	}
	cout<<ans;
	return 0;
}
