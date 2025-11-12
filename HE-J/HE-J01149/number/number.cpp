#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000];
int b=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]-'0'<=9&&s[i]-'0'>=0){
			a[b]=s[i]-'0';
			b++;
		}
	}
	for(int i=1;i<=b;i++){
		for(int j=i;j<=b;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=1;i<b;i++){
		cout<<a[i];
	}
	return 0;
}
