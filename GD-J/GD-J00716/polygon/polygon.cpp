#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,ans=0;
	cin>>n;
	vector<int> a;
	for(int i=1;i<=n;i++){
		int b;
		cin>>b;
		a.push_back(b);
	}
	sort(a.begin(),a.end());
	//for(int)
	for(int i=0;i<n;i++){
		int rmax=-1,r_all=0;
		for(int j=i;j<n;j++){
			r_all+=a[j];
			rmax=max(rmax,a[j]);
			if(r_all>2*rmax) 
			{
				ans++;
				//cout<<rmax<<" "<<r_all<<endl;
			}
			
		}
		
	}
	cout<<ans%998244353;
	return 0;
}
