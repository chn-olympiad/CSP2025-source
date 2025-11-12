#include <bits/stdc++.h>
using namespace std;
long long q;
int w,e[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>w;
	for(int i=0;i<w;i++){
		cin>>e[i];	
	}
	sort(e,e+w);
	for(int i=w-1;i>=0;i--){
		for(int j=1;j<i;j++){
			for(int k=0;k<j;k++){
				if(e[j]+e[k]>e[i]){
					q++;
				}
			}
		}
	}
	cout<<q%998244353*3;
}
