#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=1e5+10;
LL n,ans;
LL read(){
	LL f=1,s=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}
	return f*s;
}
struct Node{
	LL j1,j2,j3;
	LL cs;
}a[N]; 
bool cmp1(Node a,Node b){
	LL ami=min(abs(a.j1-a.j2),abs(a.j1-a.j3));
	LL ama=max(abs(a.j1-a.j2),abs(a.j1-a.j3));
	LL bmi=min(abs(b.j1-b.j2),abs(b.j1-b.j3));
	LL bma=max(abs(b.j1-b.j2),abs(b.j1-b.j3));
	if(ami!=bmi) return ami<bmi;
	return ama<bma;
} 
bool cmp2(Node a,Node b){
	LL ami=min(abs(a.j2-a.j1),abs(a.j2-a.j3));
	LL ama=max(abs(a.j2-a.j1),abs(a.j2-a.j3));
	LL bmi=min(abs(b.j1-b.j2),abs(b.j2-b.j3));
	LL bma=max(abs(b.j1-b.j2),abs(b.j2-b.j3));
	if(ami!=bmi) return ami<bmi;
	return ama<bma;
} 
bool cmp3(Node a,Node b){
	LL ami=min(abs(a.j3-a.j2),abs(a.j1-a.j3));
	LL ama=max(abs(a.j3-a.j2),abs(a.j1-a.j3));
	LL bmi=min(abs(b.j3-b.j2),abs(b.j1-b.j3));
	LL bma=max(abs(b.j3-b.j2),abs(b.j1-b.j3));
	if(ami!=bmi) return ami<bmi;
	return ama<bma;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	LL T;cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(LL i=1;i<=n;i++)
			a[i].j1=read(),a[i].j2=read(),a[i].j3=read();
		LL cnt[4]={0,0,0,0};
		for(LL i=1;i<=n;i++){
			if(a[i].j1>=a[i].j2&&a[i].j1>=a[i].j3) ans+=a[i].j1,cnt[1]++,a[i].cs=1;
			else if(a[i].j2>=a[i].j1&&a[i].j2>=a[i].j3) ans+=a[i].j2,cnt[2]++,a[i].cs=2;
			else if(a[i].j3>=a[i].j1&&a[i].j3>=a[i].j2) ans+=a[i].j3,cnt[3]++,a[i].cs=3;
		}
		if(cnt[1]>n/2){
			sort(a+1,a+n+1,cmp1);
			for(LL i=1;i<=n;i++){
				if(a[i].cs==1){
					if(a[i].j1-a[i].j2<a[i].j1-a[i].j3)
							cnt[2]++,cnt[1]--,ans-=a[i].j1-a[i].j2;
					else 
						cnt[3]++,cnt[1]--,ans-=a[i].j1-a[i].j3;
				}
				if(cnt[1]<=n/2)
					break;
			}
		}
		if(cnt[2]>n/2){
			sort(a+1,a+n+1,cmp2);
			for(LL i=1;i<=n;i++){
				if(a[i].cs==2){
					if(a[i].j2-a[i].j1<a[i].j2-a[i].j3)
						cnt[1]++,cnt[2]--,ans-=a[i].j2-a[i].j1;
					else 
						cnt[3]++,cnt[2]--,ans-=a[i].j2-a[i].j3;
				}
				if(cnt[2]<=n/2)
					break;
			}
		}
		if(cnt[3]>n/2){
			sort(a+1,a+n+1,cmp3);
			for(LL i=1;i<=n;i++){
				if(a[i].cs==3){
					if(a[i].j3-a[i].j2<a[i].j3-a[i].j1)
						cnt[2]++,cnt[3]--,ans-=a[i].j3-a[i].j2;
					else 
						cnt[1]++,cnt[3]--,ans-=a[i].j3-a[i].j1;
				}
				if(cnt[3]<=n/2)
					break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
