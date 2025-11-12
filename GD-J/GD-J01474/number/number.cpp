#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(isdigit(s[i]))
			a[++n]=s[i]-'0';
	sort(a+1,a+1+n,[](int x,int y){
		return x>y;
	});
	for(int i=1;i<=n;i++)
		cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
