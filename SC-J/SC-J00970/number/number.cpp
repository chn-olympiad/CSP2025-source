#include<bits/stdc++.h>
using namespace std;
string a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int x=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			
			x++;
			a[x]=s[i];
//			cout<<s[i]<<" ";
//			
//			
//			
//			
//			cout<<a[x]<<'\n';
//yyl20120904wj852184
		}
	}
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size();j++){
			if(a[i]>a[j]){
				string c=a[i];
				a[i]=a[j];
				a[j]=c;
			
			}
		}
	}
	for(int i=0;i<=s.size();i++){
		cout<<a[i];
	}
	return 0;
} 