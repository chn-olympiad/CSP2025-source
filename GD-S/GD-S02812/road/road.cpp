#include<bits/stdc++.h>
using namespace std;
int arr[10000000];
int ans;
int main(){	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
    	int a,b,c;
    	cin>>a>>b>>c;
    	arr[i]=c;	
	}
	sort(arr,arr+m)
	for(int i=m-1;i>m-1-n;i--){
		ans+=arr[i]
	}
	cout<<ans;

	return 0;
} 
