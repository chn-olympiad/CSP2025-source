#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5020;
ll n,a[N],ans;
bool f;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int len=2;len<=n-1;len++){ 
		for(int j=1;j<=n-len;j++){  
			int sum=0;
			for(int k=j;k<=j+len-1;k++){   
				sum+=a[k];
			}
			for(int k=j+len-1;k<=n;k++){  
				if(sum>a[k]) ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
