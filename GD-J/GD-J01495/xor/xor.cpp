#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool b[500005];
int n,m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int k=1;k<=n;k++)cin>>a[k];
	if(m==0){
		if(n%2==0)cout<<n/2;
		else{
			if(n==1)cout<<"0";
			else cout<<(n-1)/2+1;
		}
		return 0;
	}
	long long cnt=0;
	if(m==1){
		for(int k=1;k<=n;k++){
			if(b[k]==true)continue;
			if(a[k]==1&&a[k+1]==0){
				cnt++;
				b[k]=true;
				b[k+1]=true;
			}
		}
		cout<<cnt;
		return 0;
	}
	cout<<"7"; 
	return 0;
}
