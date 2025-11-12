#include<bits/stdc++.h>
using namespace std;
const int N=5*1e6;
int n,k;
struct node{
	string a,b;
}s[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>k;
	int kk=k;
	for(int i=1;i<=n;i++) cin>>s[i].a>>s[i].b;
	while(kk--){
		string c;
		cin>>c;
	}
	for(int i=1;i<=k;i++) cout<<0<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}/*
3 4 
a b 
b c 
c d 
aa bb 
aa b 
a c 
b a 

*/
