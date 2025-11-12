#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n,cha1[N],cha2[N],cha3[N];
struct sss{
	int one,two,three;
};
struct sss2{
	int cha,wz;
};
bool cmp(sss2 a2,sss2 b2){
	return a2.cha>b2.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		sss a[N];
		sss2 chaa[N];
		for (int i=1;i<=n;i++){
			cin>>a[i].one>>a[i].two>>a[i].three;
			chaa[i].cha=a[i].two-a[i].one;
			chaa[i].wz=i;
		}
		sort(chaa+1,chaa+n+1,cmp);
		for (int i=1;i<=n/2;i++){
			ans+=a[chaa[i].wz].two;
		}
		for (int i=n/2+1;i<=n;i++){
			ans+=a[chaa[i].wz].one;
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}

