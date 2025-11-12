#include<bits/stdc++.h>
#define v first
#define ii second
using namespace std;
const int N=1e5+5;
using pii=pair<int,int>;
using ll=long long;
int t,ans;
int n,a[5],maxx[N][5];
priority_queue<int,vector<int>,greater<int>> h[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=3;i++){
			while(h[i].size()) h[i].pop();
		}
		for(int i=1;i<=n;i++){
			int max1=0,max2=0,t=1;
			for(int j=1;j<=3;j++){
				cin>>a[j];
				if(a[j]>=max1){
					max2=max1;
					t=j;
					max1=a[j];
				}
				else if(a[j]>max2){
					max2=a[j];
				}
			}
			ans+=max1;
			int s=max1-max2;
			if(h[t].size()==n/2){
				if(s>h[t].top()){
					ans-=h[t].top();
					h[t].pop();
					h[t].push(s);
				}
				else ans-=s;
			}
			else{
				h[t].push(s);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

