#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],c[N],n,k,ans;
vector<int> e;
int q(int l,int r){
	int sum=0;
	for(int i=l;i<=r;i++){
		for(int j=1;i+j<=r;j++){
			int m=i+j;
			if(k==c[m]^c[i-1]){
				sum++;
				i=m+1;
				break;
			}
		}
	}
	return sum;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	c[i]=c[i-1]^a[i];
    	if(a[i]==k){
    		e.push_back(i);
    		ans++;
		}
	}
	if(!e.size()){
		ans+=q(1,n);
	}else{
		for(int i=0;i<e.size();i++){
			if(i==0){
				ans+=q(1,e[i]-1);
			}else{
				ans+=q(e[i-1]+1,e[i]-1);
			}
		}
		ans+=q(e[e.size()-1]+1,n);
	}
	cout<<ans;
	return 0;
}