#include<bits/stdc++.h>
using namespace std;
char s[1000100];
long long f[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	long long lj=0;
	while(cin>>s[lj]){
		lj++;
	}
	long long len=lj+1;
	for(long long i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			f[s[i]-'0']++;
		}
	}
	for(long long i=9;i>=0;i--){
		for(long long j=1;j<=f[i];j++){
			cout<<i;
		}
	}
	
	
	return 0;
}
