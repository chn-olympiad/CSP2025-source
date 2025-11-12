#include<bits/stdc++.h>
using namespace std;
int a[500010],cq[500010];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	int lj=1;
	for(int i=1; i<=n; i++,lj++) {
		cin>>a[i];
		//cout<<"a["<<i<<"]:"<<a[i]<<"\n";
		//cout<<"lj:"<<lj<<endl;
		if(a[i]==k) {
			ans++;
			lj=0;
		} else {
			bool jgmy=true;
			for(int j=lj; j>1; j--) {
				cq[j]=a[i]^cq[j-1];
				//cout<<"cq["<<j<<"]=a["<<i<<"]("<<a[i]<<")^cq["<<j-1<<"]("<<cq[j-1]<<")="<<cq[j]<<"\n";
				if(jgmy&&cq[j]==k) {
					jgmy=false;
					ans++;
					//cout<<"lj("<<lj<<")="<<j-1<<" ";
					lj=0;
					//cout<<lj<<endl;
					break; 
				}
			}
			cq[1]=a[i];
			//cout<<"cq[1]="<<a[i]<<"\n";
		}
		//cout<<"ans="<<ans<<endl;
		//cout<<endl;
	}
	cout<<ans;
	return 0;
}