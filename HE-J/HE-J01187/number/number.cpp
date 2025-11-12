#include <bits/stdc++.h>
using namespace std;
#define MXA 1000010
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[MXA],pos=0;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'<=9){
			a[pos]=s[i]-'0';
			pos++;
		}
	}
	sort(a,a+pos);
	for(int i=pos-1;i>=0;i--){
		cout<<a[i];
	}
	cout<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
