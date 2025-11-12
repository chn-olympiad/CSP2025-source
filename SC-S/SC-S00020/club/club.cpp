#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int t;
int n;
int a,b,c;
struct peo{
	int maxx,ma,idx,suf;
}p[N];
struct peo1{
	int maxx,ma,idx,suf;
}p1[N];
struct peo2{
	int maxx,ma,idx,suf;
}p2[N];
bool cmp(peo a1,peo a2){
	if(a1.suf==a2.suf) return a1.maxx>a2.maxx;
	return a1.suf>a2.suf;
}
bool cmp1(peo1 a1,peo1 a2){
	if(a1.suf==a2.suf) return a1.maxx>a2.maxx;
	return a1.suf>a2.suf;
}
bool cmp2(peo2 a1,peo2 a2){
	if(a1.suf==a2.suf) return a1.maxx>a2.maxx;
	return a1.suf>a2.suf;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int f[4]={0},ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			int m=max(a,max(b,c));
			if(m==a){
				f[1]++;
				p[f[1]].maxx=m;
				p[f[1]].ma=max(b,c);
				p[f[1]].suf=m-max(b,c);
				if(p[f[1]].ma==b){
					p[f[1]].idx=2;
				}
				else{
					p[f[1]].idx=3;
				}
			}
			else if(m==b){
				f[2]++;
				p1[f[2]].maxx=m;
				p1[f[2]].ma=max(a,c);
				p1[f[2]].suf=m-max(a,c);
				if(p1[f[2]].ma==a){
					p1[f[2]].idx=1;
				}
				else{
					p1[f[2]].idx=3;
				}
			}
			else if(m==c){
				f[3]++;
				p2[f[3]].maxx=m;
				p2[f[3]].ma=max(b,a);
				p2[f[3]].suf=m-max(b,a);
				if(p2[f[3]].ma==b){
					p2[f[3]].idx=2;
				}
				else{
					p2[f[3]].idx=1;
				}
			}
			
		}
		int m=max(f[1],max(f[2],f[3]));
		if(m>n/2){
			if(m==f[1]){
				sort(p+1,p+1+f[1],cmp);
				for(int i=n/2+1;i<=f[1];i++){
					f[p[i].idx]++;
					if(p[i].idx==2){
						p1[f[2]].maxx=p[i].ma;
					}
					else{
						p2[f[3]].maxx=p[i].ma;
					}
				}
				f[1]=n/2;
			}
			else if(m==f[2]){
				sort(p1+1,p1+1+f[2],cmp1);
				for(int i=n/2+1;i<=f[2];i++){
					f[p1[i].idx]++;
					if(p1[i].idx==1){
						p[f[1]].maxx=p1[i].ma;
					}
					else{
						p2[f[3]].maxx=p1[i].ma;
					}
				}
				f[2]=n/2;
			}
			else{
				sort(p2+1,p2+1+f[3],cmp2);
				for(int i=n/2+1;i<=f[3];i++){
					f[p2[i].idx]++;
					if(p2[i].idx==2){
						p1[f[2]].maxx=p2[i].ma;
					}
					else{
						p[f[1]].maxx=p2[i].ma;
					}
				}
				f[3]=n/2;
			}
		}
		sort(p+1,p+1+f[1],cmp);
		sort(p1+1,p1+1+f[2],cmp1);
		sort(p2+1,p2+1+f[3],cmp2);
		for(int i=1;i<=f[1];i++){
			ans+=p[i].maxx;
		}
		for(int i=1;i<=f[2];i++){
			ans+=p1[i].maxx;
		}
		for(int i=1;i<=f[3];i++){
			ans+=p2[i].maxx;
		}
		cout<<ans<<endl;
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