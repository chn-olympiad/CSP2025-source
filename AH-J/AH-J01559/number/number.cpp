#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int n=0;
	int t=a.size()-1;
	for(int i=0;i<=t;i++){
		if(a[i]<='9'&&a[i]>='0'){
			n++;
			s[n]=a[i];
		}
	}
	sort(s+1,s+1+n);
	for(int i=n;i>=1;i--){
		cout<<s[i];
	}
	return 0;
}
