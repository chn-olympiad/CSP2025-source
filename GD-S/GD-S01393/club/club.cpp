#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int A[N],cnt1,B[N],cnt2,C[N],cnt3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t,n;
	for(cin>>t;t--;){
		cin>>n,cnt1=cnt2=cnt3=0;
		int ans=0;
		for(int a,b,c,i=1;i<=n;i++){
			cin>>a>>b>>c;
			int mx=max({a,b,c}),mid=a+b+c-mx-min({a,b,c});
			ans+=mx;
			if(mx==a)A[++cnt1]=mx-mid;
			else if(mx==b)B[++cnt2]=mx-mid;
			else C[++cnt3]=mx-mid;
		}
		sort(A+1,A+cnt1+1),sort(B+1,B+cnt2+1),sort(C+1,C+cnt3+1);
		if(cnt1>n/2)
			for(int i=1;i<=cnt1-n/2;i++)ans-=A[i];
		if(cnt2>n/2)
			for(int i=1;i<=cnt2-n/2;i++)ans-=B[i];
		if(cnt3>n/2)
			for(int i=1;i<=cnt3-n/2;i++)ans-=C[i];
		cout<<ans<<endl;
	}
	return 0;
}/*
Ren5Jie4Di4Ling5%
*/
