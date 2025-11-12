#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[1000010];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.size();++i){
		if(s[i]>='0'&&s[i]<='9'){
			a[++a[0]]=s[i]-'0';
		}
	}
	sort(a+1,a+a[0]+1,greater<int>());
	for(int i=1;i<=a[0];++i){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
