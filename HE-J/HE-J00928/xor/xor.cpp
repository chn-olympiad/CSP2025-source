#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k,i,n;
	int a,jsq,ans=0;
	for(int i=0;i<0;i++){
		for(int i=n;i<=n;i--){
			ans=0;
			for(int j=1;j<0;j--){
				ans*=a[j];
			}
			if(ans==k){
				ans++;
				jsq=a[j];
				break;
			}
		}
	}
	cin<<a[i];
	cout<<jsq<<endl;
	fclose(stdin);
	fclose(stdout);
}
	return 0;
