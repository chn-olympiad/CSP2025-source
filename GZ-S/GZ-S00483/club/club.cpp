//GZ-S00483 贵阳市南明区华麟学校 陈锦江
#include<bits/stdc++.h>
using namespace std;
int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch=='-') {
		f=-1;
	}
	while(ch<='9'&&ch>='0') {
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
const int N=1e5+10086;
struct node {
	int d1,d2,d3,flag,max;
} a[N];
bool cmp(node a,node b) {
	return a.d1>b.d1;
}
bool cmp1(node a,node b) {
	return a.d2>b.d2;
}
bool cmp2(node a,node b) {
	return a.d3>b.d3;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	n=read();
	while(n--) {
		long long t,flag=1,flag1=1,cnt=0,cnt1=0,cnt2=0,ans=0;
		t=read();
		for(int i=1;i<=t;i++){
			a[i].d1=read();a[i].d2=read();a[i].d3=read();
			a[i].flag=0;
			if(a[i].d2!=0||a[i].d3){
				flag=0;
			}
		} 
		if(flag){
			sort(a+1,a+t+1,cmp);
			for(int i=1;i<=t/2;i++){
				ans+=a[i].d1;
			}
			cout<<ans<<'\n';
			continue;
		}
		sort(a+1,a+t+1,cmp);
		for(int i=1;i<=t&&cnt<t/2;i++){
			if(a[i].d1==max(a[i].d1,max(a[i].d2,a[i].d3))&&a[i].flag==0){
				ans+=a[i].d1;
				a[i].flag=1;
				cnt++;
			}
		}
		sort(a+1,a+t+1,cmp1);
		for(int i=1;i<=t&&cnt1<t/2;i++){
			if(a[i].d2==max(a[i].d2,max(a[i].d1,a[i].d3))&&a[i].flag==0){
				ans+=a[i].d2;
				a[i].flag=1;
				cnt1++;
			}
		}
		sort(a+1,a+t+1,cmp2);
		for(int i=1;i<=t&&cnt2<t/2;i++){
			if(a[i].d3==max(a[i].d1,max(a[i].d2,a[i].d3))&&a[i].flag==0){
				ans+=a[i].d3;
				a[i].flag=1;
				cnt2++;
			}
		}
		for(int i=1;i<=t;i++){
			if(a[i].flag==0){
				int q=a[i].d1,w=a[i].d2,e=a[i].d3;
				if(cnt1==t/2){
					ans+=max(q,e);
				}else if(cnt2==t/2){
					ans+=max(q,w); 
				}else{
					ans+=max(w,e);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}







