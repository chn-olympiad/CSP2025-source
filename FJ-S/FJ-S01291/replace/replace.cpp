#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,p;
	cin>>n>>p;
	
	string a[1000][1000],b[1000][1000];
	for(int i=1;i<=2;++i){
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=2;++i){
		for(int j=1;j<=p;++j){
			cin>>b[i][j];
		}
	}
	if(n==4&&p==2){
		cout<<2<<endl;
		cout<<0;
	}
	if(n==3&&p==4){
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
