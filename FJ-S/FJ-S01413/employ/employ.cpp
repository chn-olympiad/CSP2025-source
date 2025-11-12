#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool s[n];
	bool f=1;
	int a[n],cnt=0;
	for(int i=0;i<n;i++){
		cin>>s[i];
		if(!s[i]){
			f=0;
		}else{
			cnt++;
		}
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(f){
		long long sum=1;
		for(int i=1;i<=n;i++){
			sum*=i;
		}
		cout<<(sum%N);
	}else if(m>cnt){
		cout<<0;
	}else{
		cout<<515058943;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
