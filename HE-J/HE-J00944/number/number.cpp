#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int maxn;
char t[N];
int ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<=l;i++){
		if(s[i]>='0' && s[i]<='9'){
			t[ans++]=s[i];
		}
	}
	sort(t,t+ans);
	for(int i=ans-1;i>=0;i--){
		cout<<t[i];
	}
	return 0;
}
