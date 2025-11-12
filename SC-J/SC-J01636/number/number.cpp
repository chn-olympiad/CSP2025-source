#include<bits/stdc++.h>
using namespace std;
int b[1000030];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int d=0;
	cin>>a;
	for(int i=0;i<=a.size()-1;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[++d]=a[i]-'0';
		}
	}
	sort(b+1,b+d+1);
	if(b[d]==0){
		cout<<0;
	}else{
		for(int i=d;i>=1;i--){
			cout<<b[i];
		}
	}
	
	return 0; 
} 