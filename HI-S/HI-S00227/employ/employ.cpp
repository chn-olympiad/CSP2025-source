#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[501];
string s;
int b[501];
int d[501];
long long ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		b[i]=s[i-1]-'0';
	}
	int c=0;
	int mm=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=i;
		if(b[i]==0)c++;
		else if(a[i]<=c)c++;
		else {
			mm++;
		}
	}
	if(mm>=m)ans++;
	while(next_permutation(d+1,d+n+1)){
		int c=0;
		int mm=0;
		for(int i=1;i<=n;i++){
			if(b[i]==0)c++;
			else if(a[d[i]]<=c)c++;
			else {
				mm++;
			}
			if(mm==m){
				ans++;
				break;
			}
		}
	}
	cout<<ans%998244353;
	return 0;
}

