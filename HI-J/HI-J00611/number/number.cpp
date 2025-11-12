#include<bits/stdc++.h>
using namespace std;
string a[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n=0;
	cin>>s;
	n=s.size();
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i];
		}
	}
	sort(a+0,a+n);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

