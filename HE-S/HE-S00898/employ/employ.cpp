#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q,a[1000001],cnt=1,sum=0,n2=0;
string s1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>q;
	cin>>s1;
	for(int i=0;i<s1.length();i++){
		sum+=s1[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0) n2++;
	}
	if(sum==n){
		for(int i=1;i<=n2;i++){
			cnt*=i;
			cnt%=998244353;
		}
		cout<<cnt;
	}else{
		cout<<0;
	}


	return 0;
	fclose(stdin);
	fclose(stdout);
}

