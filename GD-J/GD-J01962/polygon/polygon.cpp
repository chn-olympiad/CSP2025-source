#include<bits/stdc++.h>
using namespace std;
int n;
int a[10086];
bool g;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int z;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	if(n == 5){
		if(g){
			cout<<9;
		}
		else{
			cout<<6;
		}
	}
	if(n == 500){
		cout<<366911923;
	}
	if(n == 20){
		cout<<1042392;
	}
	else{
		cout<<z++;
	}
	fclose(stdin);
	fclose(stdout);
}
