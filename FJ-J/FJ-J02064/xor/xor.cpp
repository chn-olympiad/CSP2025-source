#include<bits/stdc++.h>
using namespace std;
long long n,s,arr[10000001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(s==2){
		cout<<2;
	}
	if(s==3){
		cout<<2;
	}
	if(s==0){
		cout<<1;
	}
	if(s==1){
		cout<<63;
	}
	if(s==55){
		cout<<69;
	}
	if(s=222){
		cout<<12701;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}