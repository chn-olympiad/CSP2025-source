#include<bits/stdc++.h>
using namespace std;
string s;
long long num=0;
int a[200005];
int main(){
	freopen("number","r",stdin);
	freopen("number","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] and s[i]<='9'){
			a[num]=s[i]-'0';
			num++;
		}
	}
	sort(a,a+num);
	for(int i=num-1;i>=0;i--) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
