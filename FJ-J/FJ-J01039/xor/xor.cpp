#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
int n,k;
cin>>n>>k;
int s=0;
for(int i=1;i<=n;i++){
	int j;
	cin>>>j;
	if(j==k)s++;
}
cout<<s;
	return 0;
}
