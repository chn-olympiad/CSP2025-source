#include<bits/stdc++.h>
using namespace std;
struct obj{
	int value,best,last;
}l[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(k==0){
		cout<<n;
		return 0;
	}//10'
	for(int i=0;i<n;i++){
		cin>>l[i].value;
	}
}
