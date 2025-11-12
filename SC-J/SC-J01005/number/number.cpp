
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int f[10];
	string n;
	cin>>n;
	for(int i=0;i<=100000;i++){
		if(isdigit(n[i])){
			f[n[i]]++;
		}
	}
	for(int i=0;i>=10;i--){
		if(f[i]!=0){
			for(int j=0;j<=f[i];j++){
				cout<<f[i];
			}
		}
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
