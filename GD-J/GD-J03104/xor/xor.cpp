#include<bits/stdc++.h>
using namespace std;
const int N = 5*1e5+10;
long long q[N],s[N],sum=0,a0,a1,b,vis[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k,f=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>q[i];
		if(q[i]==1 && q[i-1]==1 && vis[i-1]==0){
			b++;
			vis[i-1]=1,vis[i]=1;
		}
		if(q[i]==1)a1++;
		else if(q[i]==0)a0++;
		else f=1;
		s[i] = s[i-1]^q[i];
	}
	
	if(f==0){
		if(a0==0)cout<<a1;
		else{
			if(k==1)cout<<a1;
			else cout<<a0+b;
		}
		
	}
	else{
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j&&q[i]==k){
				sum++;
			}
			else if((s[j]^q[i-1])==k){
				i = j;
				sum++;
				break;
			}
		}
	}
	cout<<sum;
	}
	return 0;
}
