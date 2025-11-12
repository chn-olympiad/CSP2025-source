#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int n,k,a[N],cnt1=0,cnt2=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt2+=(a[i]==1);
	}
	if(k==1)cout<<cnt2;
	else if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)cnt1++;
			else if(a[i]==a[i+1]){
				cnt1++;
				i++;
			}
		}
		cout<<cnt1;
	}
	else cout<<0;
}
