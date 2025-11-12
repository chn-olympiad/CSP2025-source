#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m;m=0;	cin>>s;
	n=size(s);
	

	for(int i=1;i<=n;i++){
		
		if(s[i]>=48 and s[i]<=57){
			m++;
			a[m]=int (s[i])-48;
			
		}

	}
	sort(a,a+m+1);
	for(int i=1;i<=m;i++){
		cout<<a[m-i+1];
	}

return 0;
}