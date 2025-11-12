#include<bits/stdc++.h>
using namespace std;
int a[1000005];
pair<int,int> s[1000005];int sp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++)cin >> a[i];
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n;j++){
			int sum=0;
			for(int k=i;k<=j;k++)
				sum^=a[k];
			if(sum==m){
				s[sp++]={i,j};
				//cout << i << ' ' << j << '\n';
			}
		}
	}
	sort(s,s+sp-1,[](pair<int,int> x,pair<int,int> y){return x.second<y.second;});
	int ans=0,past=-1;
	for(int i=0;i<sp;i++){
		if(s[i].first>past){
			ans++;
			past=s[i].second;
		}
	}
	cout << ans << '\n';
	return 0;
}
