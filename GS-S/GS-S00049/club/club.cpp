#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	int i,j=1;
	int a[10000][10];
	cin>>t;	
	int ans[t];int e[10000];
	for(int m=1;m<=t;m++){
		int n;
		cin>>n;
		if(n/2==1)return 0;
		else for(int b=1;b<=n;b++){
			cin>>a[b][1]>>a[b][2]>>a[b][3];
			e[b]=max(a[b][1],a[b][3]);
		}		
		
	
	}
	cout<<e[t]<<endl;
	
	
	
	return 0;
}

