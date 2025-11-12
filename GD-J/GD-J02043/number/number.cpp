#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[s.size()],k=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[k++]=(s[i]-'0');
	}
	sort(a,a+k,greater<int>());
	long long n=0;
	for(int i=0;i<k;i++) n=n*10+a[i];
	cout<<n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
