#include<bits/stdc++.h>
//#include<windows.h>
using namespace std;
const int maxn=5e5+7,inf=1e9;
int n,k,a[maxn],sum[maxn],l=0;
vector<int> q[maxn],ret[maxn];
struct node{
	int dx,dy;
};
node mk(int x,int y){
	node tep; tep.dx=x; tep.dy=y;
	return tep;
}
void del(int x){
	for(int g:ret[x]){
		vector<int>::iterator it=q[g].begin();
		q[g].erase(it);
	}
	return ;
}
node find(int x){
//	printf("@%d\n",x);
	int mxl=inf,mxr=inf,pl=x,pr=inf;
	while(true){
		if(pl>n) break;
		int tep=k^sum[pl];
		if(q[tep].empty()){
			pl++; continue; 
		}
		else{
			pr=*(q[tep].begin());
			if(pr==pl){
				vector<int>::iterator it=q[tep].begin();
				it++;
				if(it==q[tep].end()) continue;
				else pr=*it;
			}
			break;
		}
	}
	if(pr==inf){
		return mk(mxl,mxr);
	}
	mxl=pl; mxr=pr;
	for(int i=pl;i<=pr;i++){
	//	Sleep(1000);
		if(i>mxr) break;
		int tep=k^sum[i];
		if(q[tep].empty()) continue;
		else{
			int p=*(q[tep].begin());
			if(mxr>p && p>i){
				mxr=p;
				mxl=i;
			}
		}
		del(i);
	}
	return mk(mxl,mxr);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	sum[0]=0;
	q[0].push_back(0);
	ret[0].push_back(0);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
		q[sum[i]].push_back(i);
		ret[i].push_back(sum[i]);
	}
	int ans=0;
	for(;;){
		if(l>=n) break;
		node f=find(l);
		if(f.dx==inf) break;
		l=f.dy;
		ans++;
	}
	printf("%d",ans);
	return 0;
}
