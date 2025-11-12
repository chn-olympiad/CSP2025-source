#include<bits/stdc++.h>
using namespace std;
int a[(int)(5e5+100)],n,k,flag=1,c,d;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
		if(a[i]==1){
			c++;
		}else{
			d++;
		}
	}
	if(k==0||flag){
		cout<<(n/2);
	}else if(k==1){
		cout<<(c+d/2);
	}else if(k==0){
		cout<<(c/2+d);
	}
	return 0;
}