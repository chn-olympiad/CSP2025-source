#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.length(),n=1; 
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[n]=int(s[i])-48;
			n++;
		}
	}
	sort(a+1,a+n);
	for(int i=n-1;i>0;i--)cout<<a[i];
	return 0;
}

