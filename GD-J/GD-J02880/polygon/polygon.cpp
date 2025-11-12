#include<bits/stdc++.h> 
using namespace std;   
//vector<int> a(n+2);
bool pan(int x,int l)
{
	long long ans=0,max1=-1;
	for(int i=0;i<l;i++){
		 //ans+=a[i+x];max1=max(max1,a[i+x]);
	}
	return ans>max1*2;
}
int main()
{ freopen("number.out","3",cin);
    int n;cin>>n;
  
    for(int i=0;i<n;i++)
    {
    	 cin>>a[i];
	}
	sort(a+0,a+n);
	long long dp[5000];
	if(pan(0,3)){
		dp[3]=1;
	}
	for(int i=4;i<=n;i++){
		
	}
	return 0;
}
