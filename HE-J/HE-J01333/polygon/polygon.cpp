#include<bits/stdc++.h>
using namespace std;
int q[5001],n,w;
int main(){
	freopen("polygon.in","in",stdin);
	freopen("polygon.out","out",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>q[i];
	}
    for(int i=1;i<=n;i++){
    	for(int j=1;i<=n;i++){
    		for(int k=1;i<=n;i++){
    			if(max(max(i,j),k)*2<=i+j+k)e++
			}
		}
	}
    cout<<e;
    return 0;
}
