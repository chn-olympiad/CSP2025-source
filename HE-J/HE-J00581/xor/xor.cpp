#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[600000];
bool b[600000];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k,s=0;
    cin>>n>>k;
    b[0]=false;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	b[i]=false;
	}
	if(a[1]==k) s++;
	for(int i=2;i<=n;i++){
		int sum=a[i];
		for(int j=i-1;j>=1;j--){
			if(sum==k){	
			    s++;
				b[i]=true;
				break;
			}
			if(b[j]) break;
			sum=sum^a[j];
		}
	}
	cout<<s;
	return 0;
}
