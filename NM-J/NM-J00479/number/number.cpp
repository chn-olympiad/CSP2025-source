#include<bits/stdc++.h>
using namespace std;
string s;
const long long a=1000000;
long long k, m;
long long b[a]={};
bool mc(long long a, long long b){
	if(a>b){
		return 1;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	long long o=s.size();
	for(int i=0;i<o;i++){
		if(s[i]>='0'&&s[i]<='9'){
			m=s[i]-'0';
			k++;
			b[k-1]=m;
		}
	}
	sort(b,b+k,mc);
	for(int i=0;i<k;i++){
		cout << b[i];
	}
	return 0;
}
