#include<bits/stdc++.h>
using namespace std;
map<int,int>ca;
map<int,int>up;
map<int,int>mg;
int n,a[10000],ans;
int dp(int x){
	int l=0,r=2;
	ca[1]=a[1];
	up[1]=a[1]*2;
	ca[2]=0;
	up[2]=0;
	mg[1]=2;
	mg[2]=2;
	while(l<r){
		l++;
		//cout<<ca[l]<<" "<<up[l]<<endl;
		if(ca[l]>up[l]&&ca[l]&&mg[l]==n+1){
			ans++;
			//cout<<ca[l]<<" "<<up[l]<<endl; 
		}
		if(mg[l]<=n){
			//if(ca[l]+a[mg[l]]>=a[mg[l]]*2||ca[l]<=20){
				r++;
				ca[r]=ca[l]+a[mg[l]];
				up[r]=max(up[l],a[mg[l]]*2);
				mg[r]=mg[l]+1;
				r++;
				ca[r]=ca[l];
				up[r]=up[l];
				mg[r]=mg[l]+1;	
			//}
		}
	}
	return 0;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]==1){
		n=n-2;
		for(int i=1;i<=n;i++){
			ans+=i;
			ans%=998353244;
		}
		
	}
	else{
		dp(0);
	}
	ans%=998353244;
	cout<<ans;
	return 0;
} 
