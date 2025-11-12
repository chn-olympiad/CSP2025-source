#include<bits/stdc++.h>
using namespace std;
string s;
long long n;
long long num[20];
long long t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	s=" "+s;
	for(long long i=1;i<=n;i++){
		if('0'<=s[i] && s[i]<='9'){
			t=int(s[i])-48;
			num[t]++;
		}
	}
	for(long long ans=9;ans>=0;ans--){
		for(long long i=1;i<=num[ans];i++){
			cout<<ans;
		}
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
