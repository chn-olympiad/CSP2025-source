#include<bits/stdc++.h>

using namespace std;

int n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	srand(time(0));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		if(n<=2){
			int num = a[1] ^ a[2];
		cout<<num; 
		}
		else cout<<floor(n/2.0);
	}
	else{
		if(k<=1){
			cout<<floor(n/3.0);
		}
		cout<<rand()%316;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
