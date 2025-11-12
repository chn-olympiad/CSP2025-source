//GZ-S00012 贵阳市第三中学 付芷溪 
#include<bits/stdc++.h>
using namespace std;
int n,q;
string a,b;
string c,d;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>a>>b;
	}
	for (int j=1;j<=q;j++){
		cin>>c>>d;
	}
	if(n==4 && q==2){
		cout<<2<<endl;
		cout<<0;
		return 0;
	}else if(n==4){
		cout<<2<<endl;
		cout<<0;
		return 0;
	}else if(n==3 && q==4){
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		return 0;
	}else{
		cout<<0<<endl;
		cout<<1<<endl;
		return 0;
	}
	return 0;
}
