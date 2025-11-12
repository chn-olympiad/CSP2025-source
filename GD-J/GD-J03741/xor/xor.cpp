#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool p=1,q=1,o=1;
	int cn0=0,cn1=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			p=0;
		}
		if(a[i]!=0){
			q=0;
		}
		if(a[i]>1){
			o=0;
		}
		if(a[i]==0){
			cn0+=1;
		}
		if(a[i]==1){
			cn1+=1;
		}
	}
	if(k==0&&p==1){
		if(n%2==0){
			cout<<n/2;
		}else{
			cout<<(n-1)/2;
		}
	}else if(k==0&&q==1){
		cout<<n;
	}else if(k==0&&o==1){
		if(cn1%2==0){
			cout<<cn0+cn1/2;
		}else{
			cout<<cn0+(cn1-1)/2;
		}
		
	}
	
	if(k==1&&p==1){
		cout<<n;
	}else if(k==1&&q==1){
		if(n%2==0){
			cout<<n/2;
		}else{
			cout<<(n-1)/2;
		}
	}else if(k==1&&o==1){
		if(cn0%2==0){
			cout<<cn1+cn0/2;
		}else{
			cout<<cn1+(cn0-1)/2;
		}
		
	}
	fclose(stdin);
	fclose(stdout);
}
