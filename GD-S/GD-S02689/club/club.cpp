#include <bits/stdc++.h>
using namespace std;
int t,n,max_fangan;
int a[100005],b[100005],c[1000005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t>>n;
	for(int j=0;j<t;j++){
		int ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i]>>c[i];
		int h=max(a[i],max(b[i],c[i]));
		ans+=h;
	}
    cout<<ans<<endl;
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
