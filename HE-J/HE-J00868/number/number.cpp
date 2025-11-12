#include<iostream>
#include<string>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int m,n;
	int i=1; 
	if(s[i]<s[i+1]){
		s[i+1]=s[1];	 
	}
	string a;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
		int e=a[1];
	cout<<n<<" "<<m;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++){
			cout<<a[i];
		}
	return 0;
} 
