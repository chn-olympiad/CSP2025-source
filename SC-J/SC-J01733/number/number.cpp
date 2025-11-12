#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000001],k=1,ans;

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0; i<=s.length()-1; i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[k]=s[i]-'0';
			if(a[k]==0)  a[k]=-1; 
			k++;
		}
	}
	sort(a+1,a+k+1);
	for(int i=k; i>=1; i--){
		if(a[i]==-1)  cout<<0;
		else if(a[i]!=0)  cout<<a[i];
	}
	
	
	return 0;
}