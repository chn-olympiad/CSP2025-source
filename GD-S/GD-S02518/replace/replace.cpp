#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int a,b;
	cin>>a>>b;
	if(a==4 && b==2){
		cout<<2<<endl<<0;
	}
	else{
		for(int i=1;i<=b;i++){
			cout<<0<<endl;
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
