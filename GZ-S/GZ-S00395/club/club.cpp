//GZ-S00395 贵阳市第十八中 蒙昊锐 
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int T;
long long n;
long long cnt[3];
struct node{
	int name;
	int numm;
	int which;
}p[N];
bool flag[N];
int len=1;
bool cmp(node a,node b){
	return a.numm>b.numm;
}
long long ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>p[len].numm;
				p[len].name=i;
				p[len].which=j;
				len++;
			}
		}
		sort(p+1,p+len+1,cmp);
		int meng=n/2;
		for(int i=1;i<=len;i++){
			if(cnt[p[i].which]<meng&&flag[p[i].name]==0){
				ans+=p[i].numm;
				flag[p[i].name]=1;
				cnt[p[i].which]++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
