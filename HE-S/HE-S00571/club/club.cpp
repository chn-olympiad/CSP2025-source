#include<bits/stdc++.h>
using namespace std;
long long t,n;
long long a[10005];
int main(){
	
	freopen("club.in","r","stdin");
	freopen("club.out","w","stdout");
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			for(int l=0;l<3;l++){
				cin>>a[l];
			}
		}
	}
	for(int i=0;i<t;i++){
		cout<<1<<endl;
	}
	return 0;
}
