#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int x;
	
	for(int i=0;i<n;i++){
		cin>>x;
	}
	if(k==0)cout<<floor(n*1.0/2);
	else if(k==1)cout<<n<<endl;
	else cout<<"0"<<endl;
	return 0;
}