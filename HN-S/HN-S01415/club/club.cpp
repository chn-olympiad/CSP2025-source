#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
int n;
struct Node{
	int a[4];
}a[maxn];
bool cmp(Node A,Node B){
	int tmp1=(max(A.a[1],max(A.a[2],A.a[3]))-min(A.a[1],max(A.a[2],A.a[3]))),tmp2=(max(B.a[1],max(B.a[2],B.a[3]))-min(B.a[1],max(B.a[2],B.a[3])));
	if(tmp1==tmp2){
		return max(A.a[1],max(A.a[2],A.a[3]))>max(B.a[1],max(B.a[2],B.a[3]));
	}
	return tmp1>tmp2;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i].a[j];
			}
		}
//		maxx=-1;
//		dfs(0,0,0,0,1);
//		cout<<maxx<<endl;
		sort(a+1,a+1+n,cmp);
		int anum=0;
		int bnum=0;
		int cnum=0;
		int A=0;
		int B=0;
		int C=0;
		for(int i=1;i<=n;i++){
			int maxx=-1,maxx1=-1,maxx2=-1;
			int d=1,d2=2,d3=3;
			for(int j=1;j<=3;j++){
				if(a[i].a[j]>maxx){
					d=j;
					maxx=a[i].a[j];
				}
			}
			for(int j=1;j<=3;j++){
				if(a[i].a[j]>maxx1&&j!=d){
					d2=j;
					maxx1=a[i].a[j];
				}
			}
			if(d==1){
				if(anum<n/2){
					anum++;
					A+=maxx;
				}else if(d2==2){
					if(bnum<n/2){
						bnum++;
						B+=maxx1;
					}else{
						cnum++;
						C+=maxx2;
					}
				}else{
					if(cnum<n/2){
						cnum++;
						C+=maxx1;
					}else{
						bnum++;
						B+=maxx2;
					}
				}
			}else if(d==2){
				if(bnum<n/2){
					bnum++;
					B+=maxx;
				}else if(d2==1){
					if(anum<n/2){
						anum++;
						A+=maxx1;
					}else{
						cnum++;
						C+=maxx2;
					}
				}else{
					if(cnum<n/2){
						cnum++;
						C+=maxx1;
					}else{
						anum++;
						A+=maxx2;
					}
				}
			}else if(d==3){
				if(cnum<n/2){
					cnum++;
					C+=maxx;
				}else if(d2==1){
					if(anum<n/2){
						anum++;
						A+=maxx1;
					}else{
						bnum++;
						B+=maxx2;
					}
				}else{
					if(bnum<n/2){
						bnum++;
						B+=maxx1;
					}else{
						anum++;
						A+=maxx2;
					}
				}
			}
		}
		cout<<A+B+C<<endl;
	}
	return 0;
}
