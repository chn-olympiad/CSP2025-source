#include<bits/stdc++.h>
using namespace std;
int a[500006];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,x=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int o;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int s=0;
				for(int v=i;v<=j;v++){
					s=s^a[v];
				}
				if(s==k){
					o=j-i+1;
					if(o>x)x=o;
				} 
		}		
	}
	cout<<x;
	return 0;
}