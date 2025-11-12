#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	vector<int>a(n+1,1e9);
	a[0]=0;
	s=" "+s;
	int k=0;
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			k++;
			a[k]=s[i]-'0';
		}
	}
	sort(a.begin(),a.end());
	for(int i=k;i>=1;i--){
		cout<<a[i];
	}
}
