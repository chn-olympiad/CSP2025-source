#include <bits/stdc++.h>
using namespace std;
int n,a[9111][3],s[3],m[78],b[13];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.in","w",stdout);
	int t;
	cin>>t;
	int ans[t];
	for(int i=1;i<=t;i++){
		cin>>n;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	
	for(int i=1;i<=n;i++){
		for(int d=1;d<=n;){
			if(a[d][0]>a[d-1][0]){
			swap(a[d][0],a[d-1][0]);
			swap(a[d][1],a[d-1][1]);
			swap(a[d][2],a[d-1][2]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		
	}
	for(int i=1;i<=n;i++){
		if(a[i][0]>=a[i][1] && a[i][0]>=a[i][2])
			m[0]++;
		else if(a[i][1]>a[i][0] && a[i][1]>a[i][2])
			m[1]++;
		else
			m[2]++;
	}
	if(m[0]<=n/2 && m[1]<=n/2 &&m[2]<=n/2)
	for(int i=0;i<=n;i++){
		//s[3]+=max(a[i][0],max)
			
	}
	return 0;
 }
 
