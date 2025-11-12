#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b,n[1001],ans=0,v=0;
	cin>>a>>b;
	for(int i=0;i<a;i++)cin>>n[i];
	for(int i=0;i<a;i++){
		for(int j=i;j<a;j++){
			v=0;
			for(int k=i;k<=j;k++)
				v^=n[k];				
			if(v==b)ans++;
		}
	}
	cout<<ans;
	return 0;
}
