#include<bits/stdc++.h>
using namespace std;
int n,k,s,w=0,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		for(int v=1;v<=n-i+1;v++){
			s=0,k=0;
			for(int j=v;j<=v+i-1;j++){
				if(s<a[j]){
					s=a[j];
				}
				k+=a[j];
			}
			if(k>2*s){
				w++;
			}
		}
	}
	cout<<w;
	return 0;
}