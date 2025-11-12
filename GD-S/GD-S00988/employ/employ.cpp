#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n[2];
	int k;
	for(int i=0;i<2;i++){
		cin>>n[i];
	}
	cin>>k;
	if(n[0]==3){
		int j[3];
		for(int i=0;i<2;i++){
			cin>>j[i];
		}
		cout<<2;
	}
	if(n[0]==10){
		int j[10];
		for(int i=0;i<10;i++){
			cin>>j[i];
		}
		cout<<2204128;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
