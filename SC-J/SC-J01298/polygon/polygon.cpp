#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(n==3){
		int x,y,z;
		cin>>x>>y>>z;
		if(x+y+z>max(x,max(y,z))*2){
			cout<<1;
		}else{
			cout<<0;
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 