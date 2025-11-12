#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	vector<int> a(n+1);
	int ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int p=0;p<(1<<n);p++){
		int maxn=0,sum=0,p1=p,cnt=0;
		int i=1;
		//cout<<"p="<<p<<endl;
		while(p1!=0){
			//cout<<"i="<<i<<" ";
			if(p1%2){//cout<<"a[i]="<<a[i]<<' '; 
			maxn=max(maxn,a[i]),sum+=a[i],cnt++;
			}
			i++;
			//cout<<"i="<<i<<"\n";
			p1/=2;
		}
		//cout<<maxn<<" "<<sum<<" "<<sum-maxn<<' ';
		if(cnt>=3&&sum>maxn*2) ans++/*cout<<"y\n"*/;
		//cout<<endl;
	}
	cout<<ans;
	return 0;
}
