#include<bits/stdc++.h>
using namespace std;
long long T,n,a[100010][3],cnt1,cnt2,cnt3,ans;
vector<long long>a1,a2,a3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		cnt1=cnt2=cnt3=ans=0;
		a1.clear(),a2.clear(),a3.clear();
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
			long long maxx=max(a[i][0],max(a[i][1],a[i][2])),maxx2;
			if(maxx==a[i][0]){maxx2=max(a[i][1],a[i][2]);cnt1++;}
			else if(maxx==a[i][1]){maxx2=max(a[i][0],a[i][2]);cnt2++;}
			else {maxx2=max(a[i][0],a[i][1]);cnt3++;}
			if(maxx==a[i][0]){a1.push_back(maxx-maxx2);}
			else if(maxx==a[i][1]){a2.push_back(maxx-maxx2);}
			else {a3.push_back(maxx-maxx2);}
			ans+=maxx;
		}
		if(cnt1>n/2){
			long long res=cnt1-n/2;
			sort(a1.begin(),a1.end());
			for(int i=0;i<res;i++)ans-=a1[i];
		}
		if(cnt2>n/2){
			long long res=cnt2-n/2;
			sort(a2.begin(),a2.end());
			for(int i=0;i<res;i++)ans-=a2[i];
		}
		if(cnt3>n/2){
			long long res=cnt3-n/2;
			sort(a3.begin(),a3.end());
			for(int i=0;i<res;i++)ans-=a3[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
