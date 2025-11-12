#include<bits/stdc++.h>
using namespace std;
int n,a[100000],h;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		h+=a[i];
	}
	if(h>2*max(max(a[1],a[2]),a[3])){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 1;
}

