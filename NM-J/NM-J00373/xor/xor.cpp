#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","w",stdin);
    freopen("xor.out","r",stdout);
    
    int n,k;cin>>n>>k;
	vector<int> arr(n);
	for (int i=0;i<n;i++){
		cin>>arr[i];
	}
	int count=0;
	int s=0;
	for (int l=0;l<n;l++){
		int s=0;
		for (int r=l;r<n;r++){
			s=s^arr[r];
			if (s==k){
				count++;
				l=r+1;
				break;
			}
		}
	}
	cout<<count;
	return 0; 
}
