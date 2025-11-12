#include<bits/stdc++.h>
using namespace std;
string a;
string n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,a);
	for(int i=0;i<a.size();i++){
		if(int(a[i])>=48&&int(a[i])<=57){
			n=n+a[i];
			for(int i=0;i<n.size()+1;i++){
				if(int(n[i])<int(n[i+1])){
					swap(n[i],n[i+1]);
					
				}
				
			}
		}
		
	}
	cout<<n;
	return 0;
}
