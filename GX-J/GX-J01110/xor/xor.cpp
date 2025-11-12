#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],l,r,c,e;
int t[500005];
bool f[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		e=a[i];
		for(int j=i+1;j<=n;j++){
				if(e==k){
					e=e^a[j];
					t[i]=j;
				}else{
					e=e^a[j];
				}
			}
			
	}
//	for(int i=0;i<n;i++)cout<<c;
	if(k==0&&n<=2){
		cout<<"0";
	}
	return 0;
}
