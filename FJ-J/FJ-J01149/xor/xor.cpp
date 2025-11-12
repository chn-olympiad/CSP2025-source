#include<bits/stdc++.h>
using namespace std;
int n,k,s,w; 
int a[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		if(a[i]==k) s++;
		
	}cout<<s;
	return 0;
}/*i<1048576;
0^0=0
0^1=1
1^1=0
*/
