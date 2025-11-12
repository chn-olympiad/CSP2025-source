#include <bits/stdc++.h>
using namespace std;
string s;
int a[200000];
int main (){
	cin>>s;
	int len;
	int j=-1;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			j++;
			a[j]=s[i]-48;
		}
	}
	sort(a,a+j+1);
	for(int i=j;i>=0;i--){
		cout<<a[i];
	}	
	

	return 0;
}
