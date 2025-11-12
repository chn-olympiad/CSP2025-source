#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][5];
struct nod{
	int id,ch,cha1,cha2;
};
priority_queue<nod>q1,q2,q3;
bool operator<(const nod &a,const nod &b){
	if(a.cha1==b.cha1)return a.cha2<b.cha2;
	return a.cha1<b.cha1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		while(!q1.empty())q1.pop();
		while(!q2.empty())q2.pop();
		while(!q3.empty())q3.pop();
		int n;
		scanf("%d",&n);
		int lm=n/2;
		int x=-1,ans=0;
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			nod d;
			d.id=i;
			x=-1;
			if(a[i][1]>x){
				x=a[i][1];
				d.ch=1;
				d.cha1=max(a[i][2]-a[i][1],a[i][3]-a[i][1]);
				d.cha2=min(a[i][2]-a[i][1],a[i][3]-a[i][1]);
			}
			if(a[i][2]>x){
				x=a[i][2];
				d.ch=2;
				d.cha1=max(a[i][1]-a[i][2],a[i][3]-a[i][2]);
				d.cha2=min(a[i][1]-a[i][2],a[i][3]-a[i][2]);
			}
			if(a[i][3]>x){
				x=a[i][3];
				d.ch=3;
				d.cha1=max(a[i][2]-a[i][3],a[i][1]-a[i][3]);
				d.cha2=min(a[i][2]-a[i][3],a[i][1]-a[i][3]);
			}
			ans+=x; 
			if(d.ch==1){
				cnt1++;
				q1.push(d);
			}
			if(d.ch==2){
				cnt2++;
				q2.push(d);
			}
			if(d.ch==3){
				cnt3++;
				q3.push(d);
			}
			if(cnt1>lm){
				d=q1.top();
				q1.pop();
				int i=d.id;
				int cs=0;
				if(a[i][2]>a[i][3]){
					cs=2;
				}else cs=3;
				if(cs==2){
					ans-=a[i][1];
					ans+=a[i][2];
					cnt1--;
					cnt2++;
					d.ch=cs;
					d.cha1=max(a[i][1]-a[i][2],a[i][3]-a[i][2]);
					d.cha2=min(a[i][1]-a[i][2],a[i][3]-a[i][2]);
					q2.push(d);
				}else{
					ans-=a[i][1];
					ans+=a[i][3];
					cnt1--;
					cnt3++;
					d.ch=cs;
					d.cha1=max(a[i][1]-a[i][3],a[i][2]-a[i][3]);
					d.cha2=min(a[i][1]-a[i][3],a[i][2]-a[i][3]);
					q3.push(d);
				}
			}
			if(cnt2>lm){
				d=q2.top();
				q2.pop();
				int i=d.id;
				int cs=0;
				if(a[i][1]>a[i][3]){
					cs=1;
				}else cs=3;
				if(cs==1){
					ans-=a[i][2];
					ans+=a[i][1];
					cnt2--;
					cnt1++;
					d.ch=cs;
					d.cha1=max(a[i][2]-a[i][1],a[i][3]-a[i][1]);
					d.cha2=min(a[i][2]-a[i][1],a[i][3]-a[i][1]);
					q1.push(d);
				}else{
					ans-=a[i][2];
					ans+=a[i][3];
					cnt2--;
					cnt3++;
					d.ch=cs;
					d.cha1=max(a[i][1]-a[i][3],a[i][2]-a[i][3]);
					d.cha2=min(a[i][1]-a[i][3],a[i][2]-a[i][3]);
					q3.push(d);
				}
			}
			if(cnt3>lm){
				d=q3.top();
				q3.pop();
				int i=d.id;
				int cs=0;
				if(a[i][1]>a[i][2]){
					cs=1;
				}else cs=2;
				if(cs==1){
					ans-=a[i][3];
					ans+=a[i][1];
					cnt3--;
					cnt1++;
					d.ch=cs;
					d.cha1=max(a[i][2]-a[i][1],a[i][3]-a[i][1]);
					d.cha2=min(a[i][2]-a[i][1],a[i][3]-a[i][1]);
					q1.push(d);
				}else{
					ans-=a[i][3];
					ans+=a[i][2];
					cnt3--;
					cnt2++;
					d.ch=cs;
					d.cha1=max(a[i][1]-a[i][2],a[i][3]-a[i][2]);
					d.cha2=min(a[i][1]-a[i][2],a[i][3]-a[i][2]);
					q2.push(d);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
