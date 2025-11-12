#include<bits/stdc++.h>
using namespace std;
string s;
int ls,a[1000005],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	ls=s.size();
	for(int i=0;i<ls;i++){
		if(isdigit(s[i])) a[++cnt]=(s[i]-'0');
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	cout<<"\n";
	return 0;
}