#include<bits/stdc++.h>
#define N 1e6+5; 
using namespace std;
int a[500005],b[21],c[21],n,k;
void f(int x){
	int tip=0;
	while(x>0){
		tip++;
		if(x%2==1)b[21-tip]++;
        x=x/2;
	}
}
int main(){
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f(a[i]);
	}
	int tip=0,maxa=0;
	if(k==0){
		maxa=max(maxa,b[20]/2);
	}
	if(k==1)maxa=max(maxa,b[20]);
	while(k>0){
		tip++;
		if(k%2==0){
			maxa=max(maxa,b[21-tip]/2);
		}
		else{
			maxa=max(maxa,(b[21-tip])/2+1);
		}
		k=k/2;
	}
	cout<<maxa;
	return 0;
}