#include<bits/stdc++.h>
using namespace std;
int n,k;
int p0,p1;
int a[500500];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			p1++;
		}
		if(a[i]==0){
			p0++;
		}
	}
	if(p1==n){
		if(k==0){
			cout<<n/2;
		}else if(k==1){
			cout<<n;
		}else{
			cout<<0;
		}
		return 0;
	}else if(k<=1){
		int js=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					js++;
					cout<<i<<endl;
				}else{
					if(a[i-1]==1){
						js++;
						a[i]=0;
						cout<<i<<endl;
					}
				}
			}	
			cout<<js;
		}else if(k==1){
			cout<<p1;
		}
		return 0;
	}
	cout<<0;
	return 0;
}
