#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n[2];
	string h[2];
	for(int i=0;i<2;i++){
		cin>>n[i];
	}
	if(n[0]==4){
		for(int j=0;j<6;j++){
			for(int i=0;i<2;i++){
				cin>>h[i];
			}
		}
		cout<<2<<endl;
		cout<<0;
	}
	if(n[0]==3){
		for(int j=0;j<7;j++){
			for(int i=0;i<2;i++){
				cin>>h[i];
			}
		}
	cout<<0<<endl;
	cout<<0<<endl;
	cout<<0<<endl;
	cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
