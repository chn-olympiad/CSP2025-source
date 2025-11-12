#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000005];
int n,m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int m=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[m]=a[i]-'0';
			m++;
		}
	}
	sort(b,b+m);
	for(int i=m-1;i>=0;i--){
		cout<<b[i]; 
	}
	
	
	
	
	return 0;
}
