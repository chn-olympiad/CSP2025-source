#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long a[N]; 
long long cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+s.size(),cmp);
	for(long long i=0;i<cnt;i++){
			cout<<a[i];
	}
	return 0;
} 
