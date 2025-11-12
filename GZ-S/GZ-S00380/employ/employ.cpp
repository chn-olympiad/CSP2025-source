//GZ-S00380 遵义市第四中学 胡明轩 
#include<bits/stdc++.h>
using namespace std;
int n,q;
long long s=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>q;
	for(int i=2;i<=q;i++){
		s*=i;
	}	
	cout<<s%998244353;
	return 0;
} 
