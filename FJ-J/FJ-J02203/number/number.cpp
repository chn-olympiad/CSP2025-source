#include <bits/stdc++.h>
using namespace std;
string s;
int a[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin>>s;
	bool flag=true;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			if(s[i]!='0')
				flag=false;
			a[int(s[i])-'0']++;
		}
	}
	if(flag)
		cout<<0;
	else 
		for(int i=9;i>=0;i--)
			for(int j=1;j<=a[i];j++)
				cout<<i;
	return 0;
}
