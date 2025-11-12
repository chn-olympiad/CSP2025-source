#include<bits/stdc++.h>
using namespace std;
int n=1,a[1000003];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=int(s.size())-1;i++){
		if(('0'<=s[i])&&(s[i]<='9')){
			a[n]=int(s[i])-int('0');
			n++;	
		}
	}
	sort(a+1,a+n);
	for(int i=n-1;i>=1;i--)cout<<a[i];
	return 0;
}
                   
