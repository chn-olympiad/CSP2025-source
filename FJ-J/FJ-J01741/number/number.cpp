#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j);
	for(int i=j-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
