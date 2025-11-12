#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int n,a[maxn],b[maxn],c[maxn],res[maxn];
void in_cases(){
	int l1=0,l2=0,l3=0;
	long long ans=0;
	vector<int> dt;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		if(a[i]>=b[i] && a[i]>=c[i]){
			res[i]=1;
			ans+=a[i];
			l1++;
		}
		else if(b[i]>=a[i] && b[i]>=c[i]){
			res[i]=2;
			ans+=b[i];
			l2++;
		}
		else{
			res[i]=3;
			ans+=c[i];
			l3++;
		}
	}
	if(l1<=n/2 && l2<=n/2 && l3<=n/2){
		printf("%lld\n",ans);
		return ;
	}
	else{
		for(int i=1;i<=n;i++){
			if(l1>n/2){
				if(res[i]==1){
					dt.push_back(a[i]-max(b[i],c[i]));
				}
			}
			else if(l2>n/2){
				if(res[i]==2){
					dt.push_back(b[i]-max(a[i],c[i]));
				}
			}
			else{
				if(res[i]==3){
					dt.push_back(c[i]-max(a[i],b[i]));
				}

			}
		}
	}
	int mx=max(l1,max(l2,l3));
	sort(dt.begin(),dt.end());
	for(int i=0;i<mx-n/2;i++){
		ans-=dt[i];
	}
	printf("%lld\n",ans);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) in_cases();
	return 0;
}
