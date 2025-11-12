#include<bits/stdc++.h>
using namespace std;
struct num{
	int a,b,c,ca,i;
};
bool cmp(num a,num b){
	return a.ca<b.ca;
}
num a1[100005];
num b1[100005];
num c1[100005];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,cnt1=0,cnt2=0,cnt3=0;
		cin>>n;
		long long ans=0;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			ans=ans+max(a,max(b,c));
			if(max(a,max(b,c))==a){
				cnt1++;
				a1[cnt1]=num{a,b,c,max(a,max(b,c))-(a+b+c-max(a,max(b,c))-min(a,min(b,c))),i};
			}else if(max(a,max(b,c))==b){
				cnt2++;
				b1[cnt2]=num{a,b,c,max(a,max(b,c))-(a+b+c-max(a,max(b,c))-min(a,min(b,c))),i};
			}else{
				cnt3++;
				c1[cnt3]=num{a,b,c,max(a,max(b,c))-(a+b+c-max(a,max(b,c))-min(a,min(b,c))),i};
			}
			//qq[i]=num{a,b,c,max(a,max(b,c))-(a+b+c-max(a,max(b,c))-min(a,min(b,c))),i};
		}
		if(cnt1>n/2){
			sort(a1+1,a1+1+cnt1,cmp);
			for(int k=1;k<=cnt1-n/2;k++)ans-=a1[k].ca;
		}else if(cnt2>n/2){
			sort(b1+1,b1+1+cnt2,cmp);
			for(int k=1;k<=cnt2-n/2;k++)ans-=b1[k].ca;
		}else if(cnt3>n/2){
			sort(c1+1,c1+1+cnt3,cmp);
			for(int k=1;k<=cnt3-n/2;k++)ans-=c1[k].ca;
		}
		cout<<ans<<endl;
	}
	return 0;
}
