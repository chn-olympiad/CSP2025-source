#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int o;
int u;
int a[10000];
int b[10000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	cin>>n;
	int r=n/2;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int j=1;j<=n;j++){
		cin>>b[j];
    }
	for (int i=1;i<=n;i++){
		if (a[i]<a[i+1]){
		   	o=a[i+1];
		}
		else{
			o=a[i];
		}
	}
	for (int j=1;j<=n;j++){
		if (b[j]<b[j+1]){
			u=b[j+1];
		}
		else{
			u=b[j];
		}
	}
	cout<<o+u;
	return 0;
	fclose(stdin);
	fclose(stdout);
}