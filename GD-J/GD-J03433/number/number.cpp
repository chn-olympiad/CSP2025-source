#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],l,len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[l++]=s[i]-'0';
		}
	}
	sort(a,a+l,greater<int>());
	for(int i=0;i<l;i++){
		printf("%d",a[i]);
	}
	return 0;
}

