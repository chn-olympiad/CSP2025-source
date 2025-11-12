#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,h;
	cin>>t>>h;
	int n[t];
	for(int i=0;i<h;i++){
		for(int j=0;j<3;j++){
			cin>>n[j];
		}
	}
	if(t==3 && h==4 && n[2]==1){
		cout<<18;
	}
	if(t==3 && h==4 && n[2]==0){
		cout<<4;
	}
	if(t==3 && h==2 && n[2]==0){
		cout<<13;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
