#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],k=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
	int t=s[i]-'0';
		if(t>=0&&t<=9)a[++k]=t;
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--)
	cout<<a[i];
	return 0;
	
	
}
