#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
ll n,k,a[N],cnto,cntz;
bool ison=1,iszo=1;
int main(){
//	freopen("xor1.in","r",stdin);
//	freopen("xor1.out","w",stdout);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)ison=0;
		if(a[i]!=1&&a[i]!=0)iszo=0;
		if(a[i]==1)cnto++;
		if(a[i]==0)cntz++;
	}
	if(ison){
		cout<<n/2;
		return 0;
	}
	else if(iszo){
		if(k==1){
			cout<<cnto;
			return 0;
		}
		else{
			for(int i=1;i<n;i++){
				if(a[i]==1&&a[i+1]==1){
					cntz++;
					i++;
				}
			}
			cout<<cntz;
			return 0;
		}
	}
	return 0;
}

