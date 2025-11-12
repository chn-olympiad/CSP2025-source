#include<iostream>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,b,z;
	int a[500000];
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			b=a[i];
			for(int e=i+1;e<j;e++){
				b^=a[e];
			}if(b==k)z++;
		}
	}
	cout<<z;
	return 0;
}
