#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-48]++;
	int f=0;
	for(int i=9;i>=1;i--){
		if(a[i]){
			f=1;
			while(a[i]){
				cout<<i;
				a[i]--;
			}
		}
	}
	if(f==1)
		while(a[0]){
			cout<<"0";
			a[0]--;
		}
	else{
		cout<<"0";
	}
	return 0;
}
