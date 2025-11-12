#include<bits/stdc++.h>
using namespace std;

int n,t,cnt[5],ans,b[100005];

struct type{
	int a1,a2,a3;
};

type a[100005];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){	
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(cnt,0,sizeof(cnt));
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a1>>a[i].a2>>a[i].a3;		
	}
	for(int i=1;i<=n;i++){
		if(a[i].a1>=max(a[i].a2,a[i].a3)){
			ans+=a[i].a1;
			cnt[1]++;
			b[i]=a[i].a1-max(a[i].a2,a[i].a3);
			}
		else if(a[i].a2>=max(a[i].a1,a[i].a3)){
			ans+=a[i].a2;
			cnt[2]++;
			b[i]=a[i].a2-max(a[i].a1,a[i].a3);
			}
		else if(a[i].a3>=max(a[i].a1,a[i].a2)){
			ans+=a[i].a3;
			cnt[3]++;
			b[i]=a[i].a3-max(a[i].a1,a[i].a2);
			}
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]>=n/2){
			sort(b+1,b+1+n);
			int gap=cnt[i]-n/2;
			for(int j=1;j<=gap;j++){
				ans-=b[j];
				}
			}
		}
	cout<<ans<<"\n";
	}
	return 0;
}


