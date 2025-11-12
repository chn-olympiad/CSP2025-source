#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	if(s.size()==1){
		if(s[0]>='9'&&s[0]<='1'){
			cout<<s[0];
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	
	
	
	
	int n=0;
	string a;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='1'){
			n++;	
			a[n]=s[i];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int k=0;k<n-1;k++){
			if(a[k]<a[k+1]){
				int q;
				q=a[k+1];
				a[k+1]=a[k];
				a[k]=q;
			}
			
			
			
		}
	}
	cout<<a;
	return 0;
}
