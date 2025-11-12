#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans;
int a[500001];
void dfs(int y){
	bool zkx=false;
	int minl=INT_MAX;
	int he=0;
	for(int i=y+1;i<min(minl,n);i++){
		he=0;
		for(int j=i;j<min(minl,n);j++){
		    he=he^a[j];
		    if(he==k){
			   if(j<minl){
			   	  minl=j;
			      zkx=true;			   	  
			   }
			   break;
		    }	
		}
	}
	if(zkx){
		ans++;
		dfs(minl);
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}	
	dfs(-1);
	cout<<ans;
	return 0;
}
