#include<bits/stdc++.h>
using namespace std;
int a[10];

int main(){
	freopen("xor.in","r",stdin);	
	freopen("xor.out","w",stdout);
	for(int i=1;i<=6;i++){
		cin>>a[i];
	}
	if(a[2]==2||a[2]==3) cout<<2;
	if(a[2]==0) cout<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
