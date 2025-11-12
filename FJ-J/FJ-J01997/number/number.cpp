#include<bits/stdc++.h>
using namespace std;
int a[1000050];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string n;
	int s=0;
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]<='9'&&n[i]>='0'){
			a[s]=n[i]-'0';
			s++;
		}
	}
	sort(a,a+s);
	for(int i=s-1;i>=0;i--){
		cout<<a[i];
	}	
	return 0;
} 
