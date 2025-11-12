#include<bits/stdc++.h>
using namespace std;
int a[5000000];
int sum=0;
int in=1;
int b[5000000];
void x(int k,int n){
	
	int i1=0;
	/*for(int i=0;i<n;i++){
		if(b[i]==k){
			sum++;
			b[i]=-1;
		}
	}*/
	for(int i=0;i<n;i++){
		for(int j=0;j<in;j++){
			i1=b[i];
			if(b[i+j]==-1) {
			for(int g=0;g<in;g++){
				b[i+g]=a[i+g];
				in--;
				
			}
			return;
			}
			if(in=1) break;
			i1=i1^b[i+j];
		}
		if(i1==k){
			/*if(b[i]==-1||b[i+in]==-1){
				return ;
			}*/
			sum++;
			for(int j=0;j<in;j++){
				b[i+j]=-1;
			}
		}
	}
	in++;
	//cout<<in;
	x(k,n);
	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		b[i]=a[i];
	}
	x(k,n);
	cout<<sum;
	
	
}
