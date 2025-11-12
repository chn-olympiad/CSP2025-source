#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[1000006],b[1000678];
	for(int i=0;i<s.size();i++){
		if(s[i]<=97||s[i]>=122){
			a[i]=s[i];
		}
	}
	int n=s.size();
	sort(a,a+n);
	for(int i=n;i>=0;i--){
		cout<<char(a[i]);
		
	}
		
	

	return 0;
}
