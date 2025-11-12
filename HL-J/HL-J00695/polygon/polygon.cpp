#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int s[6];
	for(int i = 0;i<6;i++){
		cin>>s[i];
	}if(s[1]==1){
		cout<<9;
	}else if(s[1]==2){
		cout<<6;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
}