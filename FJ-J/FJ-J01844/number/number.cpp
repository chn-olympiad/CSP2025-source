#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin>>s;
	int j=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			a[j]=s[i];
			j++; 
		}
		if(s[i]=='1'){
			a[j]=s[i];
			j++; 
		}
		if(s[i]=='2'){
			a[j]=s[i];
			j++; 
		}
		if(s[i]=='3'){
			a[j]=s[i];
			j++; 
		}
		if(s[i]=='4'){
			a[j]=s[i];
			j++; 
		}
		if(s[i]=='5'){
			a[j]=s[i];
			j++; 
		}
		if(s[i]=='6'){
			a[j]=s[i];
			j++; 
		}
		if(s[i]=='7'){
			a[j]=s[i];
			j++; 
		}
		if(s[i]=='8'){
			a[j]=s[i];
			j++; 
		}
		if(s[i]=='9'){
			a[j]=s[i];
			j++; 
		}
	}
	sort(a+1,a+j+1);
	for(int i=j;i>=1;i--)
		cout<<a[i];
	return 0;
}
