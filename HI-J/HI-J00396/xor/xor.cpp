#include<bits/stdc++.h>
using namespace std;
long long aaa[1000010];
long long r[1000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;cin>>n>>k;
	long long c=0;
	long long x=0;
	for(int i=0;i<n;i++)cin>>aaa[i];
	for(int i=0;i<n;i++){
		long long sum=aaa[i];
		long long j=i;
		bool f=1;
		while(f&&j<n){
			j++;
			if(sum==k/*&&i>r[x-1]*/){
				c++;
				f=0;
				r[x]=j;
				x++;
			}
			else{
				sum=sum^aaa[j];
			}
		}
	} 
	cout<<c;
	return 0; 
}

