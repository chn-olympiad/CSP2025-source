#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],b[100],cut=0;
int main(){
	freopen("xor1.in","r",stdin);
	freopen("xor1.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int x,y=0;
		cin>>x;
		int e=0;
		while(x!=0){
			b[e]=x%2;
			x/=2;e++;
		}
		for(int j=e;j>=0;j--){
			y*=10;
			y=b[j];
		}
		a[i]=y;
	}
	for(int i=0;i<n;i++){
		if(a[i]||a[i+1]==k) cut++;
	}
	cout<<cut-1;
	return 0;
}
