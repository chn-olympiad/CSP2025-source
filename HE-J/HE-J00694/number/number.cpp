#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("numbre.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[ans]=s[i]-'0';
			ans++;
		}
	}
	sort(a,a+ans);
	for(int i=ans-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
