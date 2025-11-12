#include<bits/stdc++.h>
using namespace std;
//抄袭死全家 抄袭死全家 抄袭死全家 抄袭死全家
//抄袭死全家 抄袭死全家 抄袭死全家 抄袭死全家
//抄袭死全家 抄袭死全家 抄袭死全家 抄袭死全家
//抄袭死全家 抄袭死全家 抄袭死全家 抄袭死全家                                         
struct node{
	int m1,m2,m3;
	bool used=false;	
}a[100086];

bool cmp1(node a,node b){
	return a.m1>b.m1&&a.used==false;                                                            
}
bool cmp2(node a,node b){
	return a.m2>b.m2&&a.used==false;
}
bool cmp3(node a,node b){
	return a.m3>b.m3&&a.used==false;
}
int T,n,ans=0,renshu=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int hn=n/2;
		memset(a,0x3f,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i].m1>>a[i].m2>>a[i].m3;
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=hn&&renshu<=n;i++,renshu++){
			ans+=a[i].m1;
			a[i].used=true;
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=hn&&renshu<=n;i++,renshu++){
			ans+=a[i].m2;
			a[i].used=true;
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=hn&&renshu<=n;i++,renshu++){
			ans+=a[i].m3;
			a[i].used=true;
		}
		cout<<ans;
		ans=0,renshu=0;
	}	
	return 0;
}
