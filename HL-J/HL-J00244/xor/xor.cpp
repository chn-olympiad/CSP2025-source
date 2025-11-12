#include<bits/stdc++.h>
#include<iostream>
using namespace std;
long long a[500005];
struct qaq{
	int left,right,xorr; 
}awa[500005]; 
int n,k,cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<"1";
	} 
	/*int qwq=0,tmp;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int l=i;l<j;l++){
					tmp=a[l];
				if(l>i){
					tmp=tmp xor a[l];
				} 
			}
			if(tmp!=k){
				continue;
			}else{
				qwq++;
				awa[i].left=i;
				awa[i].right=j;
				awa[i].xorr=tmp;
			} 
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int l=i;l<j;l++){
				int tmp=a[l];
				if(l>i){
					tmp=tmp xor a[l];
				} 
			}
			if(tmp==k){
				if(awa[i].right<i){
					cnt++;
				}
			} 
		} 
		*/
	return 0;
} 
