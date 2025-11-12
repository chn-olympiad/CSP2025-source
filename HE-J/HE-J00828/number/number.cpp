#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int k=0,l=s.size();
	for(int i=0;i<=l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			k++;
			a[k]=s[i]-'0';
		}
	}
	sort(a+1,a+1+k);
	if(a[k]==0) cout<<0;
	else{
		for(int i=k;i>0;i--) cout<<a[i];
	}
	return 0;
}
