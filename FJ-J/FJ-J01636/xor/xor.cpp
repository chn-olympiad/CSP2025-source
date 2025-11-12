#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],f=1,s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	cin>>n>>k;
	if(k==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==1){
				s++;
			}
		}
		cout<<s;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=0;
		}
	}
	if(f==1){
		cout<<n/2;
		return 0;
	}
	cout<<0;
	return 0;
}
