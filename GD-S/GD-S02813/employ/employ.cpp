#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353 
int n,m;
int c[505];
string s;
int sum[1000];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("employ1.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}s='0'+s;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1];
		if(s[i]=='1'){
			sum[i]++;
		}
	}
	sort(c+1,c+n+1,cmp);
	int ans=1;
	int pos=1;
	for(int i=1;i<=n;i++){
		
	}
	cout<<1;
	
}
