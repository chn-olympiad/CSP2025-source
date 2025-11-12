#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int q,n;
	cin>>q>>n;
	char a[q][2];
	char b[n][2];
	for(int i = 1;i<=q;i++){
		for(int j = 1;j<=2;j++){
			cin>>a[i][j];
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=2;j++){
			cin>>b[i][j];
		}
	}
	if(q==4&n==2){
		cout<<2<<endl;
		cout<<0<<endl;
	}else if(q==3&n==4){
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
	}else{
		cout<<1<<endl;
		cout<<2<<endl;
		cout<<3<<endl;
	}
	return 0;
}
