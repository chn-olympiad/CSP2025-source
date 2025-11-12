#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main(void){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,c1=0,c2=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) c1++;
		if(a[i]==1||a[i]==0) c2++;
	}if(k==0&&c1==n){
		cout<<n/2;
	}else if(k==0&&c2==n){
		c2=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) c2++;
			else if(a[i]==a[i+1]){
				a[i+1]=333;
				c2++;
			}
		}cout<<c2;
	}else if(k==1&&c2==n){
		c2=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) c2++;
		}cout<<c2;
	}else{
		cout<<"我不会你还问我？？？？？？";
	}

	return 0;
}
