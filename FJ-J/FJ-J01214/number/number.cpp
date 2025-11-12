#include <bits\stdc++.h>
using namespace std;
string s;
int ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	char a[s.size()];
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			ans++;
			a[ans]=s[i];
		}
	}
	for(int i=0;i<sizeof(a);i++){
		for(int j=i+1;j<sizeof(a);j++){
		if(a[i]<a[j]){
			swap(a[i],a[j]);
		}
	}
	}
	cout<<a;
	return 0;
}
