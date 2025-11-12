#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
int k=0;
int sum=0;
int maxl=INT_MIN;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int kk=1;kk<=n;kk++){
		sum=0;
		for(int i=kk;i<=n;i++){
			int r=i,ans=a[i];
			while(r<=n){
				//cout<<r;
				if(ans!=k){
					r++;
					ans=ans^a[r];
				}
				else break;
				
			}
			if(ans==k){
				sum++;
				i=r;
			}
		}
		maxl=max(maxl,sum);
	}
	cout<<maxl;
	return 0;
}
