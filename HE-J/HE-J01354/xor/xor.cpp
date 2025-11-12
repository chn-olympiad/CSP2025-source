#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,sum1,sum2=0;
	cin>>n>>k;
	vector<long long>v(n);
	for(long long i=0;i<n;i++)cin>>v[i];
	for(long long i=0;i<v.size();i++){
		for(long long j=i;j<v.size();j++){
			sum1=v[i];
			for(long long m=i+1;m<=j;m++){
		        sum1=sum1^v[m];			
			}
			if(sum1==k){
				sum2++;			
				i=j;
				break;
			}


	    }
	}
	cout<<sum2<<endl;
	return 0;
}
