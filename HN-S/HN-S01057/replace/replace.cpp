#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1; 
int n,q;string a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=x.size()-a[i].size();j++){
				for(int k=j;k<=j+a[i].size()){
					if(x[k]==a[i][k]) 
				}
			}
		}
	}
	return 0;
}
