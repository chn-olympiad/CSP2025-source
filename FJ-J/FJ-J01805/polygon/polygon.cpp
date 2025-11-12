#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int mb[5005];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>mb[i];
	}
	if(n<3)cout<<"0";
	if(max(mb[1],max(mb[2],mb[3]))*2<mb[1]+mb[2]+mb[3])cout<<"1";
	else cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
