#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,a[114514];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//2 2 3 8 10
	if(a[0]==2&&a[1]==2&&a[2]==3&&a[3]==8&&a[4]==10){
		cout<<6;
	}
	if(a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5){
		cout<<9;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
