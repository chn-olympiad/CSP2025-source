#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size(),cnt=-1; 
	int a[l]={};
	if (l==1){
		cout<<s;
		return 0;
	}
	for (int i=0;i<l;i++){
		if (s[i]>='0'&&s[i]<='9'){
			cnt++;
			a[cnt]+=s[i]-48;
		}
	}
	sort(a,a+cnt+1);
	for (int i=cnt;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}

