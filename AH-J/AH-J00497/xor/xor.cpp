#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000005],sum_0,sum_1,sum_k;
int main(){
	cin.tie(0);
	cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			sum_1++;
		}
		if(a[i]==0){
			sum_0++;
		}
		if(a[i]==k){
			sum_k++;
		}
	} 
	if(k==0){
	    cout<<sum_0+sum_1/2;
		return 0;
	}
	if(k==1){
		cout<<sum_1;
		return 0;
	}
	cout<<sum_k;
	return 0;
}
//wo xiang shang mi huo xing wei da shang
//wo shi nailong!!!
//nailong bao you wo cspj1=
