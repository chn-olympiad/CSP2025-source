#include<bits/stdc++.h>
using namespace std; 
string n;
int m[1000000],p=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]-'0'>=0 and n[i]-'0'<=9){
			m[p]=n[i]-'0';
			p++;
		}	
	}
	
	for(int i=0;i<p;i++){
		for(int j=0;j<p;j++){
			if(m[j]>m[i]) swap(m[j],m[i]);
		}
	}
	for(int i=p-1;i>=0;i--) cout<<m[i];
	

	
	
	
	
	
	return 0;
}
