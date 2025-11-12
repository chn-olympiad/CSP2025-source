#include<bits/stdc++.h>
using namespace std;

int a[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		int jilu=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				jilu++;
			}
		}
		cout<<jilu;
	}else{
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
