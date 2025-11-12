#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int a,ch1[N],ch2[N],ch3[N];
int cnt1=0,cnt2=0,cnt3=0;
bool cmp(int a,int b){
	return a<b;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%lld",&T);
	while(T--){
		int n;
		cin>>n;
		long long ans=0;
		cnt1=0;cnt2=0;cnt3=0;
		for(int i=1;i<=n;i++){
			int f,g,h;
			scanf("%lld%lld%lld",&f,&g,&h);
			a=max(f,max(g,h));
			if(a==f){
				cnt1++;
				ch1[cnt1]=a-max(g,h);	
			} 
			else if(a==g){
				cnt2++;
				ch2[cnt2]=a-max(f,h);
			}
			else if(a==h){
				cnt3++;
				ch3[cnt3]=a-max(f,g);
			}
			ans+=a;
		}
		int siz=n/2;
		int tot=0;
		if(cnt1>siz){
			sort(ch1+1,ch1+cnt1+1,cmp);
			while(cnt1>siz){
				cnt1--;
				ans-=ch1[++tot];
			}
		}
		else if(cnt2>siz) {
			sort(ch2+1,ch2+cnt2+1,cmp);
			while(cnt2>siz){
				cnt2--;
				ans-=ch2[++tot];
			}
		}
		else if(cnt3>siz){
			sort(ch3+1,ch3+cnt3+1,cmp);
			while(cnt3>siz){
				cnt3--;
				ans-=ch3[++tot];
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

