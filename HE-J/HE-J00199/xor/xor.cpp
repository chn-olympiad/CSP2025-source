#include<bits/stdc++.h>
using namespace std;
long long int n,k,a[1000006],d[1000006],q=0;
int f(long long int i,long long int s){
	long long int z=0;
	for(;i<n;i++){
		z=z xor a[i];
		if(z==k){
			for(i++;i<=n;i++){
				f(i,s+1);
				return 0;
			}
		}
	}
	d[q]=s;
	q++;
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		f(i,0);
	}
	sort(d-1,d+q);
	cout<<d[q-1];
	return 0;
}
