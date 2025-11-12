#include<bits/stdc++.h>
using namespace std;
string a;
int s[1000005],m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			s[++m]=a[i]-'0';
		}
	}
	sort(s+1,s+1+m);
	for(int i=m;i>=1;i--){
		cout<<s[i];
	}
	return 0;
}
