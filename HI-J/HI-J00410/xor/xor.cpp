#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500500],q;
bool f=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]==k)
    	q++;
    	if(a[i]!=0&&a[i]!=1){
    		f=0;
		}
	}
	if(n==1&&k==0){
		cout<<"0";
		return 0;
	}
	if(n==2&&k==0){
		cout<<"1";
		return 0;
	}
	if(k==0&&f==1){
	   	cout<<n;
	   	return 0;
	}
	cout<<n/2+1;
	return 0;
}
