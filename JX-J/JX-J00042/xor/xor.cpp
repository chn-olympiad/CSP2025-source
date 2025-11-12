#include<bits/stdc++.h>
using namespace std;
int n,k,ans,l;
int a[1000005];
map<int,bool>m;
vector<int>v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int x=k;
		for(int j=i;j>l;j--){
			x^=a[j];
			if(x==0){
				ans++;
				l=i;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
