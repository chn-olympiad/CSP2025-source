#include<bits/stdc++.h>
using namespace std;
int a[5005],n;
int bian=3;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n];
    for(int i=1;i<=n;i++){
        cin>>a[i]; 
	}
	long long ans=0;
	vector<int> v;
	for(int i=0;i<n;i++){
	    for(int j=i+1;j<n;j++){
	        for(int k=j+1;j<n;j++){
	        	if(a[i]+a[j]+a[k]>max(max(a[i],a[j]),a[k])*2) ans++;
			}
		}
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
