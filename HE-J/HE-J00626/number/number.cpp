#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
string s;
long long a[N]={};
long long sum1[N]={};
long long sum2[N]={};
int cnt=0;
int cnt1=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	s=' '+s;
	for(int i=1;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			cout<<i;
			a[i]--;
		}
	}
	cout<<'\n';
	return 0;
}
