#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,a[100005],b[100005],c[100005],s1[100005],s2[100005],sum=0,maxn=0;
		cin>>n;
		int m=n;
		for(int j=1;j<=n;j++){
			vector<int> v;
			cin>>a[j]>>b[j]>>c[j];
			maxn=max(a[j],max(b[j],c[j]));
			v.push_back(a[j]);
			v.push_back(b[j]);
			v.push_back(c[j]);
			sort(v.begin(),v.end());
			s1[j]=v[2]-v[1];
			s2[j]=v[2]-v[1];
		}
		sort(s1+1,s1+n+1);
		for(int j=1;j<=n;j++){
			for(int k=m;k>=1;k--){
				if(s1[k]==s2[j]){
					sum+=max(a[j],max(b[j],c[j]));
					break;
				}
			}
			m--;
		}
		cout<<sum+maxn<<'\n';
	}
	return 0;
}
