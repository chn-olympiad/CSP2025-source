#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string n,s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	LL len=n.size();
	for(LL i=0;i<len;i++){
		if(n[i]>='a') continue;
		s+=n[i];
	}
	sort(s.begin(),s.end());
	reverse(s.begin(),s.end());
	cout<<s;
	return 0;
}
