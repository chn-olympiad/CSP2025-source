#include<bits/stdc++.h>
using namespace std;
int a,k,x,sum=0,maxx=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>k;
	for (int i=0;i<a;i++){
		cin>>x;
		if (x==k){
			sum++;
		}
		maxx=max(x,maxx);
	}
	if (maxx<2 || k==0){
		cout<<sum;
		return 0;
	}
	else{
		cout<<a/k+sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
