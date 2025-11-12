#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s1,s2;
	cin>>s1;
	int j=0;
	for(int i=0;i<s1.size();i++){
		if((s1[i]<='9'&&s1[i]>='0')){
			s2[j]=s1[i];
			j++;
		}
	}
	for(int i=0;i<j;i++){
		if(s2[i]=='0') a[i]=0;
		if(s2[i]=='1') a[i]=1;
		if(s2[i]=='2') a[i]=2;
		if(s2[i]=='3') a[i]=3;
		if(s2[i]=='4') a[i]=4;
		if(s2[i]=='5') a[i]=5;
		if(s2[i]=='6') a[i]=6;
		if(s2[i]=='7') a[i]=7;
		if(s2[i]=='8') a[i]=8;
		if(s2[i]=='9') a[i]=9;
	}
	sort(a,a+j);
	for(int i=j-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
