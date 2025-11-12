#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	string s;
	int a[1000005],flg=0;	
	cin>>s;
	for (int i=0;i<s.size();i++){
		if(s[i]-'0'>=0 && s[i]-'0'<=9){
			a[flg++]=s[i]-'0';
		}		
	}
	for(int i=0;i<flg-1;i++){
		for(int j=0;j<flg-i-1;j++){
			if(a[j]<a[j+1]) swap(a[j],a[j+1]);		
		}
	}
	for (int i=0;i<flg;i++){
		cout<<a[i];
	
	}	
	return 0;
}
