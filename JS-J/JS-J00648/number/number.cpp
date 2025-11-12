#include<bits/stdc++.h>
using namespace std;
string s,a="";
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a+=s[i];
	}
	sort(a.begin(),a.end());
	int f=0;
	for(int i=a.size()-1;i>=0;i--){
		if(a[i]!='0') f=1;
		if(f||i==0) cout<<a[i];
	}
	return 0;
}//0u050hz08t2ibm70y4exp04u6m44838cont753674e569zh6hpkxr9tyd0l1odacalb5u0a835e7631x9581dy8pnui496e7t0bx
