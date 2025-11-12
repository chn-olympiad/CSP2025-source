#include<bits/stdc++.h>
using namespace std;
string str[500005]; 
int main(){
	int n,k,sum=0;
	cin>>n>>k;
	int a[500005]={},b[25]={};
	//输入加转换二进制 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			str[i]="0";
//			cout<<str[i]<<endl;
			continue;
		}
		int t=a[i];
		int top=0;
		while(t!=0){
			b[top]=t%2;
			t/=2;
			str[i]+=b[top++]+'0';
			
		} 
//		cout<<str[i]<<endl;
//		while(top>=1){
//			str[i]+=b[--top]+'0';
//		}
//		cout<<str[i]<<endl;
	}
	int l,r;
	for(l=1;l<=n;l++){
		for(r=l;r<=n;r++){
			if(l==r){
				if(l==k){
					sum++;
				}
				continue;
			}
			
		}
	}
	return 0;
}
