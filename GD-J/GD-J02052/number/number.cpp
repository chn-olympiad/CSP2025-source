#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1e6+10;
int ar[N],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ar[i]=s[i]-'0';
			cnt++;
		}
	}
	sort(ar,ar+s.size(),greater<int>());
	for(int i=0;i<cnt;i++){
		cout<<ar[i];
	}
	
	
	
	return 0;
}
