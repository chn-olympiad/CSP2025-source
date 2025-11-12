#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int T,n,ans;
int a[N][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		vector<int> num1,num2,num3;
		int cnt1=0,cnt2=0,cnt3=0;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int maxn=max(a[i][1],max(a[i][2],a[i][3]));
			ans+=maxn;
			if(a[i][1]==maxn) num1.push_back(i),cnt1++;
			else if(a[i][2]==maxn) num2.push_back(i),cnt2++;
			else num3.push_back(i),cnt3++;
		}
		vector<int> t;
		if(cnt1>n/2){
			for(int i:num1) t.push_back(min(a[i][1]-a[i][2],a[i][1]-a[i][3]));
			sort(t.begin(),t.end());
			for(int i=0;i<cnt1-n/2;i++) ans-=t[i];
		}
		if(cnt2>n/2){
			for(int i:num2) t.push_back(min(a[i][2]-a[i][1],a[i][2]-a[i][3]));
			sort(t.begin(),t.end());
			for(int i=0;i<cnt2-n/2;i++) ans-=t[i];
		}
		if(cnt3>n/2){
			for(int i:num3) t.push_back(min(a[i][3]-a[i][2],a[i][3]-a[i][1]));
			sort(t.begin(),t.end());
			for(int i=0;i<cnt3-n/2;i++) ans-=t[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}