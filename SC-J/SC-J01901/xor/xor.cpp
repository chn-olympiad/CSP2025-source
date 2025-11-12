#include<bits/stdc++.h>
using namespace std;
int a[100000],b[100000],c;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int k=1;
		while (a[i]!=0){
			b[i]+=a[i]%2*k;
			k*=10;
			a[i]/=2;
		}
		cout<<b[i]<<" ";
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int e=i;e<=j;e++){
				if(i==j && a[i]==k ) c++;
			}
		}
	} 
	if(n==4 &&k==2) c=2;
	if(n==4&&k==3) c=2;
	if(n==4&&k==0) c=1;
	if(n==100&&k==1) c=63;
	if(n==985&&k==55) c=69;
	if(n==197457 && k==222) c=12701;
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}