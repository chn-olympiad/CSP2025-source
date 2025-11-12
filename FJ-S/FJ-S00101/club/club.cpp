#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a1[100001];
int a2[100001];
int a3[100001];
int b1[100001];
int b2[100001];
int b3[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	cin>>n;
	int ans=0;
	for(int j=1;j<=t;j++){	
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			b1[i]=a1[i];
			b2[i]=a2[i];
			b3[i]=a3[i];
			sort(b1+1,b1+n+1);
			sort(b2+1,b2+n+1);
			sort(b3+1,b3+n+1);
			ans+=b1[n]+b2[n]+b3[n];
		}
	}

	
	
	
	return 0;
} 
