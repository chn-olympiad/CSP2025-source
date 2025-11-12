#include<bits/stdc++.h>
using namespace std;
int ans,a[100005],n;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>ans>>ans;
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n/2;i++){
			ans+=a[i];
		}
		cout<<ans;
	}
} 
