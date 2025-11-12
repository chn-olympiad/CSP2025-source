#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	int ix=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			ix++;
			a[ix]=s[i]-48;
		}
	}
	sort(a+1,a+ix+1);
	for(int i=ix;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 