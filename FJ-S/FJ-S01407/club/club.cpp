#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct student{
	int c1;
	int c2;
	int c3;
}d[100100];
bool cmp1(student a,student b){
	if(a.c1!=b.c1) return a.c1>b.c1;
	else if(a.c2!=b.c2) return a.c2>b.c2;
	else return a.c3>b.c3;
}
bool cmp2(student a,student b){
	if(a.c2!=b.c2) return a.c2>b.c2;
	else if(a.c1!=b.c1) return a.c1>b.c1;
	else return a.c3>b.c3;
}
bool cmp3(student a,student b){
	if(a.c3!=b.c3) return a.c3>b.c3;
	else if(a.c1!=b.c1) return a.c1>b.c1;
	else return a.c2>b.c2;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&d[i].c1,&d[i].c2,&d[i].c3);
		int ma=0;
		for(int c=1;c<=3;c++){
			int cnt=0;
			int cc1=0,cc2=0,cc3=0;
			if(c==1) sort(d+1,d+n+1,cmp1);
			if(c==2) sort(d+1,d+n+1,cmp2);
			if(c==3) sort(d+1,d+n+1,cmp3);
			for(int i=1;i<=n/3+1;i++){
				if(c==1) cnt+=d[i].c1,cc1++;
				if(c==2) cnt+=d[i].c2,cc2++;
				if(c==3) cnt+=d[i].c3,cc3++;
			}
			for(int i=n/3+2;i<=n;i++){
				int c1c=d[i].c1,c2c=d[i].c2,c3c=d[i].c3;
				int nn=(int)(c1c>c2c && cc1<=n/2)*c1c+(int)(c2c>c1c && cc2<=n/2)*c1c;
				nn=(int)(nn>c3c)*c3c+(int)(c3c>=nn && cc3<=n/2)*c3c;
				cnt+=nn;
				if(nn==d[i].c1) cc1++;
				else if(nn==d[i].c2) cc2++;
				else cc3++;
			}
			ma=max(ma,cnt);
		}
		cout<<ma<<endl;
	}
	return 0;
}


