#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][3]={0},a2[100005]={0},ans=0,limit=-1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	for(int s=1;s<=t;s++){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		limit=n/2;
		for(int i=1;i<=n;i++){
			a2[i]=a[i][1];
		}
		sort(a2+1,a2+n+1,greater<int>());
		for(int i=1;i<=limit;i++){
			ans+=a2[i];
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
