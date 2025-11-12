#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p=998244353;
int n,m,c[505],ff=1,ct,go_away,a[505];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==m){
		int flag=0;
		for(int i=0;i<s.size();i++){
			if(s[i]!='1'){
				flag=1;
				break;
			}
		}
		if(!flag){
			int sum=1;
			for(int i=1;i<=n;i++)sum=(sum*i)%p;
			cout<<sum;
		}
		else cout<<0;
		return 0;
	}
	else if(n<=11){
		int all=0;
		for(int i=1;i<=n;i++)a[i]=i;
		do{
			int cnt=0,sum=0;
			for(int i=1;i<=n;i++){
				if(cnt>=c[a[i]])cnt++;
				else if(s[i-1]=='0')cnt++;
				else sum++;
			}
			if(sum>=m)all++;
			if(all>=p)all-=p;
		}while(next_permutation(a+1,a+n+1));
		cout<<all;
		return 0;
	}
	cout<<0;
	return 0;
}
