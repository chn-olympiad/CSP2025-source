#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor1.in","r",stdin);
	freopen("xor1.out","w",stdout);
	int n,k,number=0;
	cin>>n>>k;
	int r[n];
	for(int i=0;i<n;i++){
        cin>>r[i];
	}
	sort(r,r+n);
    for(int i=0;i<n-1;i++){
	 for(int j=i+1;j<n;j++){
        if(r[i]-r[j]==k) number++;
        }
    }
    cout<<number;
    return 0;
}
