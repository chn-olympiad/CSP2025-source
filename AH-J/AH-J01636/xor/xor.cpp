#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0,h=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(h==0)h=a;
		else h=h^a;
		if(h==k){
			cnt++;
			h=0;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
