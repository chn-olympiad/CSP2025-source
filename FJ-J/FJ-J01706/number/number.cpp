#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int changdu=s.size();
	int a[1000001];
	int flag=0;
	for(int i=0;i<changdu;i++){
		if(s[i]>='0'&&s[i]<='9'){
			flag++;
			a[flag]=s[i]-48;
		}
	}
	sort(a+1,a+1+flag);
	for(int i=flag;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
