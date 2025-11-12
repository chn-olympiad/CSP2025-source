#include<bits/stdc++.h>
using namespace std;
pair<long long,long long> f[5005];
bool cmp(pair<long long,long long> a,pair<long long,long long> b){
	return a.first > b.first;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>f[i].first,f[i].second=i;
	sort(f+1,f+1+n*m,cmp);
	int t=0;
	for(int i=1;i<=n*m;i++){
		if(f[i].second==1){
			t=i;
			break;
		}
	}
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt++;
				if(cnt==t){
					cout<<i<<" "<<j;
					return 0;
				}
			} 
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				cnt++;
				if(cnt==t){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
}
