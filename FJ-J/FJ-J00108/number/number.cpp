#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5; 
int s[N];
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int i,k=0;
	for(i=0;i<=a.size()-1;i++){
		if(a[i]>=48&&a[i]<=57) s[++k]=a[i]-48;
	}
	sort(s+1,s+k+1);
	for(i=k;i>=1;i--) cout<<s[i];
	//fclose(stdin); 
	//fclose(stdout);
	return 0;
}
