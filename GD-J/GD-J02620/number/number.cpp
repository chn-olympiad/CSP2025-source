#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++k]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1,greater<int>());
	for(int i=1;i<=k;i++)cout<<a[i];
	return 0;
} 
