#include<bits/stdc++.h> 

using namespace std;

long long n,a[5001],ans;

void DFS(long long sum,long long mmax,long long start,long long size){
	
	if(sum>mmax*2&&size>=3){
		
		ans++;
		
		return;
	}
	
	for(long long i=start;i<n;i++){
		
		DFS(sum+a[i],max(mmax,a[i]),start+1,size+1);
	}
}

int main(){
	
	freopen("polygon.in","r",stdin);
	
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	
	for(long long i=0;i<n;i++){
		
		cin>>a[i];
	}
	
	DFS(0,0,0,0);
	
	cout<<ans;
	
	fclose(stdin);
	
	fclose(stdout);
	
	return 0;
}
