#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int aa[N];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int t=1; 
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			aa[t]=s[i]-'0';
			t++;
		}
	}
	sort(aa+1,aa+t,cmp);
	for(int i=1;i<t;i++){
		cout<<aa[i];
	}
	return 0;
} 
