#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main(){
	bool p=true;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			p=false;
			break;
		}
	}
	if(p){
		cout<<n/2;
		return 0;
	}
	p=true;
	int c=0,d=0;
	for(int i=1;i<=n;i++){
	     if(a[i]==1) c++;
		   if(a[i]==1&&a[i+1]==1&&b[i]!=1){
				d++;
				a[i+1]=1;
	        }
		if(a[i]!=1&&a[i]!=0){
			p=false;
			break;
		}
	}
	if(p){
		if(k==0){
			cout<<n-c+d;
		}else if(k==1){
			cout<<c;
		}
		return 0;
	}
	return 0;
}