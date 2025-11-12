#include <iostream>
#include <cstdio>
using namespace std;
int a[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		int q=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			q++;
		}
		if(q%2==0)cnt++;
	}}
	if(k==0){
	
		int i=1;
		while(i<n){
		if(a[i]!=a[i+1]){
				cnt++;i+=2;
			}
		else if(a[i]==0&&a[i+1]==0){
			cnt++;i++;
		}
		else if(a[i]==1&&a[i+1]==1){
			cnt++;i+=2;
		}
	}
	if(a[n-1]==0&&a[n]==0)cnt++;
	}
	cout<<cnt;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
