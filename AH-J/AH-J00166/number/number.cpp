#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long a[1000001];
	string s;
	cin>>s;
	int l=s.size(),ans=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[ans]=s[i]-'0';
			ans++;
		}
	}
	sort(a,a+ans+1);
	for(int i=ans;i>0;i--){
		cout<<a[i];
	}
	return 0;
}
