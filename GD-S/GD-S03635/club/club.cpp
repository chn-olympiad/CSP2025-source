#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int pos,val1,val2,val3;
};
bool cmp1(node a,node b){
	return max(a.val2-a.val1,a.val3-a.val1)>max(b.val2-b.val1,b.val3-b.val1);
}
bool cmp2(node a,node b){
	return max(a.val1-a.val2,a.val3-a.val2)>max(b.val1-b.val2,b.val3-b.val2);
}
bool cmp3(node a,node b){
	return max(a.val1-a.val3,a.val2-a.val3)>max(b.val1-b.val3,b.val2-b.val3);
}

void solve(){
	int n;cin>>n;
	int arr[n+1][4];
	for(int i=1;i<=n;i++){
		
		cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
	} 
	vector<node> g1;
	vector<node> g2;
	vector<node> g3;
	for(int i=1;i<=n;i++){
		int ma=0;
		for(int j=1;j<=3;j++) ma=max(ma,arr[i][j]);
		if(arr[i][1]==ma){
			g1.push_back({i,arr[i][1],arr[i][2],arr[i][3]});
		}else if(arr[i][2]==ma){
			g2.push_back({i,arr[i][1],arr[i][2],arr[i][3]});
		}else if(arr[i][3]==ma){
			g3.push_back({i,arr[i][1],arr[i][2],arr[i][3]});
		}
	}
	
	int a=g1.size(),b=g2.size(),c=g3.size();
	
	//cout<<a<<b<<c<<endl;
	int ans=0;
	if( a>n/2){
		sort(g1.begin(),g1.end(),cmp1);
		for(int i=0;i<a-(n/2);i++){
			ans+=max(g1[i].val2,g1[i].val3);
		}
		for(int i=a-(n/2);i<a;i++){
			ans+=g1[i].val1;
		}
		for(int i=0;i<g2.size();i++){
			ans+=g2[i].val2;
		}
		for(int i=0;i<g3.size();i++){
			ans+=g3[i].val3;
		}
	}else if( b>n/2){
		sort(g2.begin(),g2.end(),cmp2);
	
		for(int i=0;i<b-(n/2);i++){
			ans+=max(g2[i].val1,g2[i].val3);
		}
		for(int i=b-(n/2);i<b;i++){
			ans+=g2[i].val2;
		}
		for(int i=0;i<g1.size();i++){
			ans+=g1[i].val1;
		}
		for(int i=0;i<g3.size();i++){
			ans+=g3[i].val3;
		}
	}else if( c>n/2){
		sort(g3.begin(),g3.end(),cmp3);
		for(int i=0;i<c-(n/2);i++){
			ans+=max(g1[i].val2,g1[i].val1);
		}
		for(int i=c-(n/2);i<c;i++){
			ans+=g3[i].val3;
		}
		for(int i=0;i<g2.size();i++){
			ans+=g2[i].val2;
		}
		for(int i=0;i<g1.size();i++){
			ans+=g1[i].val1;
		}
	}else {
		for(int i=0;i<g3.size();i++){
			ans+=g3[i].val3;
		}
		for(int i=0;i<g2.size();i++){
			ans+=g2[i].val2;
		}
		for(int i=0;i<g1.size();i++){
			ans+=g1[i].val1;
		}
	}
	cout<<ans<<endl;
	return ; 
	
} 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
