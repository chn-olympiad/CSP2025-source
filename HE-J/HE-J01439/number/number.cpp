#include <bits/stdc++.h>
using namespace std;
string s; 
int a[1000005];
int l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		int c=s[i];
		if(c>=48&&c<=57){
			a[l]=s[i]-48;
			l++;
		}
	}
	sort(a,a+l);
	for(int i=l-1;i>=0;i--)printf("%d",a[i]);
	return 0;
}
