#include<iostream>
#include<algorithm>
using namespace std;
int n,k,m=1,n=1;
int a[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]!=1){
    		m=0;
		}
		if(a[i]!=1&&a[i]!=0){
			n=0;
		}
	}
	if(m==1){
		cout<<n/2;
	}
	else{
		cout<<n/2+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
