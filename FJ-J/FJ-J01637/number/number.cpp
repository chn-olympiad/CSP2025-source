#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int ans[1000000],beg=0;
	for(int i=0;i<a.length();i++){
		int nem=int(a[i]);
		if(nem>=48&&nem<=57) {
			ans[beg]=nem-48;
			beg++;
		}
	}	
	sort(ans,ans+beg+1,greater<int>());
	for(int i=0;i<beg;i++){
		cout<<ans[i];
	}
	return 0;
} 
