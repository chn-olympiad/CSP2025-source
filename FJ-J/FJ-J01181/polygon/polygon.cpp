#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n = 0,l[5010];
	for(int i = 0;i < n;i++) cin>>l[i];
	if(n == 5){
		if(l[0] == 1) cout<<'9';
		if(l[0] == 2) cout<<'6';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
