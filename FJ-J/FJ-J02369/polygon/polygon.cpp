#include<bits/stdc++.h>
using namespace std;

int a[5005];
int s[5005];
int n,ans;

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	
	for(int i=2;i<=n;i++){
		int j=-1;
		int l=0,r=i-2,mid;
		while(l<=r){
			mid=(l+r)/2;
			if((s[i]-s[mid])>a[i+1]){
				j=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
//		cout<<j<<" "<<i<<"\n";
		if(j!=-1) ans+=j+1;
	}
	cout<<ans;
	
	return 0;
}
/*

2 1 0 3
2 3 3 0

*/
