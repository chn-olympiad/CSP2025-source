#include<bits/stdc++.h>
using namespace std;
long long t,n,sum1,sum2,sum3,ccz1[100005],ccz2[100005],ccz3[100005],a,b,c,ans,cnt1,cnt2,cnt3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while (t--){
		ans=0;
		cin>>n;
		sum1=sum2=sum3=cnt1=cnt2=cnt3=0;
		for (int i=1;i<=n;i++){
			cin>>a>>b>>c;
			ccz1[i]=a-max(b,c);
			ccz2[i]=b-max(a,c);
			ccz3[i]=c-max(a,b);
			sum1+=a;
			sum2+=b;
			sum3+=c;
			if (max(max(a,b),c)==a) cnt1++;
			else if (max(max(a,b),c)==b) cnt2++;
			else cnt3++;
			ans+=max(max(a,b),c);
		}
		sort(ccz1+1,ccz1+n+1);
		sort(ccz2+1,ccz2+n+1);
		sort(ccz3+1,ccz3+n+1);
		if (cnt1>n/2){
			for (int i=1;i<=n/2;i++){
				sum1-=ccz1[i];
			}
			ans=sum1;
		}
		else if (cnt2>n/2){
			for (int i=1;i<=n/2;i++){
				sum2-=ccz2[i];
			}
			ans=sum2;
		}
		else if (cnt3>n/2){
			for (int i=1;i<=n/2;i++){
				sum3-=ccz3[i];
			}
			ans=sum3;
		}
		cout<<ans<<"\n";
	}
}
