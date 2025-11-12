#include<bits/stdc++.h>
using namespace std;
string s;
int nm[1000007];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr); 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length(),le=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			le++;
			nm[le]=s[i]-'0';
		}
	}
	sort(nm+1,nm+1+le);
	for(int i=le;i>0;i--){
		cout<<nm[i];
	}
	return 0;
} 
