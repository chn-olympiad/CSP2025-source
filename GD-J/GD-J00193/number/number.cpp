#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	int n=0;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n++]=s[i]-'0';
		}
	}
	sort(a,a+n,greater<int>());
	for(int i=0;i<=n;i++){
		cout<<a[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
