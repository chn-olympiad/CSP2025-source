#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5+1000;

int n,t;
long long ans;
struct Node{
	int a,b,c;
}a[MaxN];
vector<int> A,B,C;

bool cmpa(int x,int y){
	return max(a[x].b,a[x].c)-a[x].a>max(a[y].b,a[y].c)-a[y].a;
}
bool cmpb(int x,int y){
	return max(a[x].a,a[x].c)-a[x].b>max(a[y].a,a[y].c)-a[y].b;
}
bool cmpc(int x,int y){
	return max(a[x].b,a[x].a)-a[x].c>max(a[y].b,a[y].a)-a[y].c;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		for(int i=1;i<=n;i++){
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				A.push_back(i);
				ans+=a[i].a;
			}
			else if(a[i].b>a[i].a&&a[i].b>a[i].c){
				B.push_back(i);
				ans+=a[i].b;
			}
			else{
				C.push_back(i);
				ans+=a[i].c;
			}
		}
		if(A.size()>(n/2)){
			sort(A.begin(),A.end(),cmpa);
			for(int i=0;i<A.size()-(n/2);i++){
				int j=A[i];
				ans+=max(a[j].b,a[j].c)-a[j].a;
			}
		}
		else if(B.size()>(n/2)){
			sort(B.begin(),B.end(),cmpb);
			for(int i=0;i<B.size()-(n/2);i++){
				int j=B[i];
				ans+=max(a[j].a,a[j].c)-a[j].b;
			}
		}
		else if(C.size()>(n/2)){
			sort(C.begin(),C.end(),cmpc);
			for(int i=0;i<C.size()-(n/2);i++){
				int j=C[i];
				ans+=max(a[j].b,a[j].a)-a[j].c;
			}
		}
		printf("%lld\n",ans);
		ans=0;
		A.clear();
		B.clear();
		C.clear();
	}
	
	return 0;
} 
