#include<bits/stdc++.h>
using namespace std;
string s;
int sle,num=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sle=s.length();
	int a[sle+5];
	for(int i=0;i<sle;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[num]=s[i]-48;
			num++;
		}
	}
	sort(a+1,a+num);;
	for(int i=num-1;i>=1;i--)
		cout<<a[i];
	return 0;
}
