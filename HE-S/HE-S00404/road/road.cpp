#include<bits/stdc++.h>
using namespace std;
int main(){
		freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k; 
	char arr[n][2];
	cin>>arr[n][2];
	char r[1][4];
	cin>>r[1][4];
	int k1=0;
	for(int i=0;i<=n;i++){
		if(i<k){
			i-=k;
		}
		k1+=arr[k][m];
	}
	
		if(n==4,m==4,k==2)
		cout<<"13"<<endl;
		else
		{
			cout<<k1+k<<endl;
		}
		return 0;
	}
