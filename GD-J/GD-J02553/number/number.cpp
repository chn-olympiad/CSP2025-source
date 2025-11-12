#include<bits/stdc++.h>
using namespace std;
string s;
int a[100010],l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&'9'>=s[i]){
			a[l]=s[i]-'0';
			l++;
		}
	}
	sort(a,a+l);
	for(int i=l-1;i>=0;i--)cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
