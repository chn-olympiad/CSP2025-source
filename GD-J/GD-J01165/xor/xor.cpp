#include<bits/stdc++.h>
using namespace std;
int a[int(5e5+7)];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	int re=0,i=0,j=0;
	while(j<n&&i<=j){
		int l=a[i];
		for(int m=i+1;m<=j;m++) l=l^a[m];
		if(l==k) re++,j++,i=j;
		else if(l<k||i==j) j++;
		else i++;
	}
	cout<<re<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
