#include <bits/stdc++.h>
using namespace std;
string s;
long long a[100005];
long long t;
int main()
{
	cin.tie(0);cout.tie(0);
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	cin >> s;
	int len=s.size();
	for(int i=0;i<=len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[i]=s[i]-'0';//É¸Êý×Ö 
			t++;
		}
	}
	for(int i=0;i<=len;i++){
		for(int j=i+1;j<=len;j++){
			if(a[i]<a[j]){
				swap(a[j],a[i]);
			}
		}
	}
	for(int i=0;i<t;i++){
		cout << a[i];
	}
	return 0;
}

