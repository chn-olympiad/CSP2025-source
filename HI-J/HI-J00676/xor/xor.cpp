#include<bits/stdc++.h>
using namespace std;
int n[1000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int t,l,sum=0;
	cin>>t>>l;
	for(int i=1;i<=t;i++){
		cin>>n[i];
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j=t;j++){
			int c=n[i];
			for(int z=i;z<j;z++){
				if(c!=n[z]){
				c^=n[z];
			}
			}
			if(c==l){
				sum++;
			}
		}
	}
	cout<<sum;
	
	return 0;
}
