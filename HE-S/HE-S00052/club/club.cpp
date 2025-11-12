#include <bits/stdc++.h>
using namespace std;
int a[1001000],b[1001000],c[1001000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int n,j,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>j;
		int m=1;
		for(int g=1;g<=j;g++){
			cin>>a[m]>>a[m+1]>>a[m+2];
			m+=3;
		}
		sort(a+1,a+j*3+1);
		for(int i=j*3;i>=j*3-j;i--){
			ans++;
		}
		cout<<ans;
	}
	/*
	int n,j;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>j;
		for(int g=1;g<=j;g++){
			cin>>a[i]>>b[i]>>c[i];
		}
	*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
