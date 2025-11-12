#include<iostream>
using namespace std;
int b[500010];
int xr(int a,int b){
	int c=0,cc=1;
	while(a||b){
		if(a%2!=b%2){
			c+=cc;
		}cc*=2;
		a/=2;
		b/=2;
	}return c;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,t=0,cnt=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		for(int j=t;j<i;j++){
			b[j]=xr(b[j],a);
		}b[i]=a;
		for(int j=t;j<=i;j++){
			if(b[j]==k){
				t=j+1;
				cnt++;
				break;
			}
		}
	}cout<<cnt<<endl;
	return 0;
}
