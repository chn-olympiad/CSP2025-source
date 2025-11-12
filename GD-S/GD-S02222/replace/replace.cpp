#include<bits/stdc++.h>
using namespace std;
int n,q;
string a,b,c="\0",d="\0";
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		c+=a;d+=b;
	}
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		c+=a;d+=b;
	}
	int aa=1;
	aa+=n;
	aa+=q;
	aa=aa-n-q;
	for(int i=1;i<=n;i++){
		aa+=n;
		aa-=n;
	}
	if(aa==1){
		for(int i=1;i<=q;i++)cout<<aa-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
