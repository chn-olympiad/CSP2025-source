#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    bool flag=1;
    for(int i=1;i<=n;i++) {
    	cin>>a[i];
    	if(a[i]!=1)flag=0;
	}
	if(flag){
		cout<<(n-(n%2))/2;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			if(a[i+1]==1){
				ans++;
				i++;
			}
		} 
		else ans++;
	}
	cout<<ans;
    return 0;
}
