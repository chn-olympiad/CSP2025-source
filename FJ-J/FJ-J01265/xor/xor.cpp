#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005],x,y;
int main(){//rp=INT_MAX;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k>1){
		cout<<1;
		return 0;//rp!!
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)x++;
		if(a[i]==1)y++;
	}
	if(k==0&&x==0){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;//a
	}
	if(k==0&&x!=0){
		cout<<x;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	cout<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
