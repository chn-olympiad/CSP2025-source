#include<iostream>
#include<vector>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum,ans = 0;
	bool tag = false;
	cin>>n>>k;
	vector<int>a(n,0); 
	vector<bool>b(n,false);
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<=n-i;j++){
			//cout<<j<<j+i<<"\n";
			tag = false;
			if(b[j] == true)continue;
			sum = a[j];
			for(int l = j+1;l<=j+i;l++){
				if(b[l] == true){
					tag = true;
					break;
				}
				sum = sum xor a[l];
			}
			if(!tag && sum==k){
				for(int l = j;l<=j+i;l++){
					b[l] = true;
				}
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
