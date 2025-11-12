#include <bits/stdc++.h>
using namespace std;

int n,k;
long long a[500005];
int s;
int temp;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (long long i=0;i<n;i++){
		for (long long j=i;j<n;j++){
			temp=a[i];
			for (long long l=i;l<=j;l++){
				cout<<temp<<" "<<a[l]<<endl;
				temp=temp^a[l];
				
			}
			if (temp==k){
				s+=1;
			}
		}
	}
	cout<<endl;
	cout<<s<<endl;


	return 0;
}
