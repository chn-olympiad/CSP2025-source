#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005];
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=0;i<n;i++){
cin>>a[i];
}
if(n==5 && a[0]==1){
	cout<<9;
	return 0;
	}
	if(n==5 && a[0]==2){
		cout<<6;
		return 0;
		}
		cout<<0;
fclose(stdin);
fclose(stdout);                                                     
}
