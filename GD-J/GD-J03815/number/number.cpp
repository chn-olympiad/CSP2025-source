#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+7;
string s;
long long a[MAXN];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j,greater<long long>());
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	return 0;
}
