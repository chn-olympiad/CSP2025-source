#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	int nx[502];
	for(int i=1;i<=n;i++){
		cin>>nx[i];
	}
	int nxx[502];
	int c;
	for(int i=1;i<=n;i++){
		int min=nx[1];
		for(int j=1;j<n;j++){
			c=1;
			if(min<nx[j]){
				min=nx[j];
				c=i;
			}
		}
		nxx[i]=min;
		nx[c]=n;
	}
	int p=0;
	for(int i=1;i<=n;i++){
		int z=0;
		if(z>=nxx[i]){
			z++;
		}
		else if(a[i-1]!=1){
			z++;
		}
		else{
			p++;
		}
	}
	cout<<p-1;
	return 0;
}
