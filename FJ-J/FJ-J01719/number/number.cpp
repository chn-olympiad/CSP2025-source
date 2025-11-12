#include<bits/stdc++.h>
using namespace std;
string a;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int j=0;
	sort(a.begin(),a.end());
	for(int i=a.size()-1;i>=0;i--){
		if(a[i]<='9'&&a[i]>='0'){
			s[j]=a[i];
			j++;
		}
	}
	for(int i=0;i<j;i++){
		cout<<s[i];
	}
	return 0;
} 
