#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000006];
long long k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++k]=s[i];
		}
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--){
		cout<<a[i];
	}
	//100
	return 0;
} 