#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=0;
	char n=s.size();
	char a[n]={};
	for(int i=0;i<n;i++){
		if(s[i]<='9' && s[i]>='0'){
			a[j]=s[i];
			j++;
		}
	}
	sort(a,a+n);
	for(int i=j;i>=0;i--){
		cout<<(a[i]-45);
	}
	return 0;
}
