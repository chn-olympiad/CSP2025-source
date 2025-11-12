#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,a[N][4];
struct node{
	int b[4];
};
vector<int>A,B,C;
int ans;
bool cmp1(int x,int y){
	return max(a[x][2],a[x][3])-a[x][1] > max(a[y][2],a[y][3])-a[y][1];
}
bool cmp2(int x,int y){
	return max(a[x][1],a[x][3])-a[x][2] > max(a[y][1],a[y][3])-a[y][2];
}
bool cmp3(int x,int y){
	return max(a[x][1],a[x][2])-a[x][3] > max(a[y][1],a[y][2])-a[y][3];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		A.clear();B.clear();C.clear();
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]) A.push_back(i);
			else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]) B.push_back(i);
			else C.push_back(i);
		}
		ans=0;
		for(int i=0;i<A.size();i++) ans+=a[A[i]][1];
		for(int i=0;i<B.size();i++) ans+=a[B[i]][2];
		for(int i=0;i<C.size();i++) ans+=a[C[i]][3];
		if(A.size()<=n/2 && B.size()<=n/2 && C.size()<=n/2){
			printf("%d",ans);
		}else{
			if(A.size()>n/2){
				sort(A.begin(),A.end(),cmp1);
				for(int i=0;i<A.size()-n/2;i++){
					ans-=a[A[i]][1];
					ans+=max(a[A[i]][2],a[A[i]][3]);
				}
				printf("%d",ans);
			}
			if(B.size()>n/2){
				sort(B.begin(),B.end(),cmp2);
				for(int i=0;i<B.size()-n/2;i++){
					ans-=a[B[i]][2];
					ans+=max(a[B[i]][1],a[B[i]][3]);
				}
				printf("%d",ans);
			}
			if(C.size()>n/2){
				sort(C.begin(),C.end(),cmp3);
				for(int i=0;i<C.size()-n/2;i++){
					ans-=a[C[i]][3];
					ans+=max(a[C[i]][1],a[C[i]][2]);
				}
				printf("%d",ans);
			}
		}
		printf("\n");
	}
	return 0;
}
