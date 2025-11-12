#include <iostream>
using namespace std;
int a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		int t=s[i]-'0';
		if(t>=0||t<=9)
			a[t]++;
	}
	for(int i=9;i>=0;i--)
		for(int j=0;j<a[i];j++)
			cout<<i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
