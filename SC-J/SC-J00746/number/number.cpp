#include<iostream>
#include<algorithm>
using namespace std;
int a[100001];
int main()
{
	long long int top=1,t=0;
	string s;
	cin>>s;
	for(int i=0;i<=s.length()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[top++]=s[i]-48;
		}
	} 
	sort(a+1,a+top+1);
	for(int i=top;i>=1;i--){
		t=t*10+a[i];
	}
	cout<<t/10;
}