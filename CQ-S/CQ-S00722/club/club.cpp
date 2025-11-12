#include<bits/stdc++.h>
using namespace std;
long long t,n,maxn[100005];
struct {
	long long a,b,c;
}a[100005];
vector<long long> s[4];
bool cmp1(long long A,long long B){
	return maxn[A]+a[B].a<maxn[B]+a[A].a;
}
bool cmp2(long long A,long long B){
	return maxn[A]+a[B].b<maxn[B]+a[A].b;
}
bool cmp3(long long A,long long B){
	return maxn[A]+a[B].c<maxn[B]+a[A].c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		s[1].clear();
		s[0].clear();
		s[2].clear();
		s[3].clear();
		for(long long i=1;i<=n;i++){
			maxn[i]=0;
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>=a[i].b && a[i].a>=a[i].c){
				s[1].push_back(i);
				maxn[i]=max(a[i].b,a[i].c);
			}
			else if(a[i].b>=a[i].c && a[i].b>=a[i].a){
				s[2].push_back(i);
				maxn[i]=max(a[i].a,a[i].c);
			}
			else if(a[i].c>=a[i].b && a[i].c>=a[i].a){
				s[3].push_back(i);
				maxn[i]=max(a[i].b,a[i].a);
			}
			else s[0].push_back(i);
		}
		long long ans=0;
		if(s[1].size()>n/2){
			sort(s[1].begin(),s[1].end(),cmp1);
			for(long long i=0;i<n/2;i++){
				ans+=a[s[1][i]].a;
			}
			for(long long i=n/2;i<s[1].size();i++){
				ans+=maxn[s[1][i]];
			}
			for(long long i=0;i<s[2].size();i++){
				ans+=a[s[2][i]].b;
			}
			for(long long i=0;i<s[3].size();i++){
				ans+=a[s[3][i]].c;
			}		
			for(long long i=0;i<s[0].size();i++){
				ans+=a[s[0][i]].c;
			}
		}
		else if(s[2].size()>n/2){
			sort(s[2].begin(),s[2].end(),cmp2);
			for(long long i=0;i<n/2;i++){
				ans+=a[s[2][i]].b;
			}
			for(long long i=n/2;i<s[2].size();i++){
				ans+=maxn[s[2][i]];
			}
			for(long long i=0;i<s[1].size();i++){
				ans+=a[s[1][i]].a;
			}
			for(long long i=0;i<s[3].size();i++){
				ans+=a[s[3][i]].c;
			}		
			for(long long i=0;i<s[0].size();i++){
				ans+=a[s[0][i]].c;
			}
		}
		else if(s[3].size()>n/2){
			sort(s[3].begin(),s[3].end(),cmp3);
			for(long long i=0;i<n/2;i++){
				ans+=a[s[3][i]].c;
			}
			for(long long i=n/2;i<s[3].size();i++){
				ans+=maxn[s[3][i]];
			}
			for(long long i=0;i<s[1].size();i++){
				ans+=a[s[1][i]].a;
			}
			for(long long i=0;i<s[2].size();i++){
				ans+=a[s[2][i]].b;
			}
			for(long long i=0;i<s[0].size();i++){
				ans+=a[s[0][i]].c;
			}
		}
		else{
			for(long long i=0;i<s[1].size();i++){
				ans+=a[s[1][i]].a;
			}
			for(long long i=0;i<s[2].size();i++){
				ans+=a[s[2][i]].b;
			}
			for(long long i=0;i<s[3].size();i++){
				ans+=a[s[3][i]].c;
			}		
			for(long long i=0;i<s[0].size();i++){
				ans+=a[s[0][i]].c;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

