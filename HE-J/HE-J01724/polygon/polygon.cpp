#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int q,u=0,a=0,s=0;
	cin>>q;
	int r[q],w[q];
	for(int i=0;i<q;i++){
		cin>>r[i];
	}
	for(int i=2;i<=q;i++){
		for(int p=0;p<q,p++){
			for(int k=p;k<i;k++){
				a+=r[k];
			}s=max(r+k,r+k+i);
			if(a>s){
				u++;	
			}
		}
		cout<<u;
	}
	return 0;
}
