#include<bits/stdc++.h>
using namespace std;
struct z{
	int x,y,z;
}a[100001];
bool cmp1(z x,z y){
	return x.x-max(x.y,x.z)>y.x-max(y.y,y.z);
}
bool cmp2(z x,z y){
	return x.y-max(x.x,x.z)>y.y-max(y.x,y.z);
}
bool cmp3(z x,z y){
	return x.z-max(x.y,x.x)>y.z-max(y.y,y.x);
}
vector<z>a1,a2,a3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ans,i;
	scanf("%d",&t);
	while(t--){
		ans=0;
		a1.clear(),a2.clear(),a3.clear();
		scanf("%d",&n);
		for(i=1;i<=n;++i){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			ans+=max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].x>a[i].y&&a[i].x>a[i].z)
				a1.push_back(a[i]);
			else if(a[i].y>a[i].x&&a[i].y>a[i].z)
				a2.push_back(a[i]);
			else
				a3.push_back(a[i]);
		}
		if(a1.size()>n/2){
			sort(a1.begin(),a1.end(),cmp1);
			for(i=a1.size()-1;i>=n/2;--i)
				ans-=a1[i].x-max(a1[i].y,a1[i].z);
		}
		else if(a2.size()>n/2){
			sort(a2.begin(),a2.end(),cmp2);
			for(i=a2.size()-1;i>=n/2;--i)
				ans-=a2[i].y-max(a2[i].x,a2[i].z);
		}
		else if(a3.size()>n/2){
			sort(a3.begin(),a3.end(),cmp3);
			for(i=a3.size()-1;i>=n/2;--i)
				ans-=a3[i].z-max(a3[i].y,a3[i].x);
		}
		printf("%d\n",ans);
	}
	return 0;
}
