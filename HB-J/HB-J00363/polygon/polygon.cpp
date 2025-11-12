#include<bits/stdc++.h>
using namespace std;
int n,a[5050],k=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w"stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int A=0;A<=n-3;A++){
		for(int B=A+1;B<=n-2;B++){
			for(int C=B+1;C<=n-1;C++){
				if(A+B+C>2*max(A,max(B,C)))k++;
			}
		}
	}
	cout<<k;
	return 0;
}
