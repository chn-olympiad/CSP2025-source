#include<iostream>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	int a[n];
	int j=0;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i){
		if(int(a[i]^j)==k){
			cnt++;
			j=0;
		}else{
			j=int(a[i]^j);
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}