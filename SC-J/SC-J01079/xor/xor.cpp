#include<bits/stdc++.h>
using namespace std;
int a[500005];
vector<int> v;
int co(int begin,int end){
	int ans=a[begin];
	for(int i=begin+1;i<=end;i++){
		if(a[i]==-1)return -1;
		ans=(ans xor a[end]);
	}
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	v.push_back(0);
	v.push_back(0);
	int n,k;cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			a[i]=-1,ans++;
			v.push_back(i);
		}
	}
	v.push_back(n+1);
	int kk=1;
	while(kk<v.size()-1){
		
		int begin=v[kk]+1,end=v[kk+1]-1;
		for(int i=2;i<=end-begin+1;i++){
			for(int j=begin;j<=end-i+1;j++){
				int an=co(j,j+i-1);
				if(an==-1)continue;
				if(an==k){
					ans++;
					for(int kkk=j;kkk<=j+i-1;kkk++)a[kkk]=-1;
				}
			}
		}
		kk++;
	}
	cout<<ans;
} 