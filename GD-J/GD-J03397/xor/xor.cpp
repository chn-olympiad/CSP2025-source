#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,sum[500001],a[500001];
map<int,vector<int> > m;
vector<int> t;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	m[0].push_back(0); 
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=x;
		sum[i]=sum[i-1]^x;
		m[sum[i]].push_back(i);
	}
	int lastr=-1,ans=0;
	for(int r=1;r<=n;r++){
		if(m[sum[r]^k].size()==0){
		//	cout<<"Tiao"<<endl;
			continue;
		}
	//	cout<<(sum[r]^k)<<endl;
		t=m[sum[r]^k];
		int l=0,R=t.size();
		while(l+1<R){
			int mid=(l+R)/2;
			if(t[mid]<=r){
				l=mid;
			}
			else{
				R=mid;
			}
		}
		l=t[l];
		//cout<<a[r]<<endl;
		if((l>lastr&&(l!=r))||((l==r)&&a[l]==k)){
		//	cout<<'L'<<l<<endl;
			ans++;
			lastr=l;
		} 
	}
	cout<<ans;
}
