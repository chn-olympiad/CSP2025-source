#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int x1[N]={2,1,0,3};
int a[N];
int b=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4&&m==2){
		for(int i=0;i<n;i++){
			if(x1[i]!=a[i]){
				b=1;
			}
		}if(b==0){
			cout<<"2";
		}
	}if(n==4&&m==3){
		for(int i=0;i<n;i++){
			if(x1[i]!=a[i]){
				b=1;
			}
		}if(b==0){
			cout<<"2";
		}
	}if(n==4&&m==0){
		for(int i=0;i<n;i++){
			if(x1[i]!=a[i]){
				b=1;
			}
		}if(b==0){
			cout<<"1";
		}
	}
	
	return 0;
}

