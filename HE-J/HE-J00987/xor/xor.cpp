#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int n,k,c[911],d;
bool e[911];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		int dy;
		for(int j=i;j<=n;j++){
			dy=c[i];
			for(int k=i+1;k<=j;k++){
				dy^=c[k];
			}

		if(dy==k){
			int tf=0;
			for(int k=i;k<=j;k++){
				if(e[k]){
					tf=1;
					break;
				}
			}
			if(tf==0){
				for(int k=i;k<=j;k++){
					e[k]=1;
				}
				d++;
			}
		}
	}
}
	cout<<d;
	return 0;
}
