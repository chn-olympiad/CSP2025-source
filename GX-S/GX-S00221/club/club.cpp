#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n,num=0,cnt=0;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		long long arr[t][n]={};
		for(int j=0;j<n;j++){
			num=0;
			for(int z=0;z<3;z++){
				cin>>arr[j][z];
				if(arr[j][z]>=num){
					num=arr[j][z];
				}
			}
			cnt+=num;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
