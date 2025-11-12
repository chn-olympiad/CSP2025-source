#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	string s1;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9')s1+=s[i];
	}
	sort(s1.begin(),s1.end());
	reverse(s1.begin(),s1.end());
	cout<<s1;
	return 0;
}
