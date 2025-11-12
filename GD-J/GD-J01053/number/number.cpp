#include<bits/stdc++.h>
using namespace std;
string s;
int a[10000000],k;
bool camp(int a,int b){
	return a>b;
}
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if((int)(s[i]-'0')>=0 && (int)(s[i]-'0')<=9)
			a[++k]=(int)(s[i] - '0');
	}
	sort(a+1,a+k+1,camp);
	for(int i=1;i<=k;i++)
		cout<<a[i];
	
	return 0;
}
