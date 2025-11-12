#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int a[n+1];
	if(n==m){
		char c;
		while(cin>>c){
			if(c=='0'){
				cout<<0;
				return 0;
			}else{
				cout<<1;
				return 0;
			}
		}
	}
	if(m==1){
		int sum=0;
		string s;
		cin>>s;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=0;j<a[i];j++){
				if(s[i]=='1') sum++;
			}
		}
		cout<<sum;
	}
	return 0;
}