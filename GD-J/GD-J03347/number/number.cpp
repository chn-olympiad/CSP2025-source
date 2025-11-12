#include<bits/stdc++.h>
using namespace std;
int b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	int c=0;
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]=='0'){
			c+=1;
		}
		else if(a[i]>'0' and a[i]<='9'){
			b[i]=a[i]-'0';
		}
		else{
			continue;
		}
	}
	sort(b,b+a.size());
	for(int i=a.size()-1;i>=0;i--){
		if(b[i]!=0){
			cout<<b[i];
		}
	}
	for(int i=1;i<=c;i++){
		cout<<0;
	}
}
