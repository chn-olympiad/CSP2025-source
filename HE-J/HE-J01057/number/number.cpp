#include<bits/stdc++.h>
using namespace std;
string s,ans;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0'+1]++;
	}
	for(int i=10;i>=0;i--){
		for(int j=0;j<a[i];j++){
			ans+=to_string(i-1);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
