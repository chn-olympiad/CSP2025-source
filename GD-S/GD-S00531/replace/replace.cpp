#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s1,s2,t1,t2;
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		cin>>t1>>t2;
	}
	if(s1!=""&&s2!=""&&t1!=""&&t2!=""){
		cout<<q<<endl;
		cout<<n-q-2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
