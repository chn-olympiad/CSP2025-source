#include<bits/stdc++.h>
using namespace std;
int t,n,la[100005][10],my1,my2,my3,vis[100005],anss;
struct nd{
	int nm,idd;
}ssa[100005],ssb[100005],ssc[100005];
bool operator < (const nd &a,const nd &b){
	return a.nm<b.nm;
};
void ast(){
	priority_queue<nd> q;
	for(int i=1;i<=n;i++){
		q.push(ssa[i]);
	}for(int i=1;i<=n;i++){
		ssa[i]=q.top();
		q.pop();
	}
}void bst(){
	priority_queue<nd> q;
	for(int i=1;i<=n;i++){
		q.push(ssb[i]);
	}for(int i=1;i<=n;i++){
		ssb[i]=q.top();
		q.pop();
	}
}void cst(){
	priority_queue<nd> q;
	for(int i=1;i<=n;i++){
		q.push(ssc[i]);
	}for(int i=1;i<=n;i++){
		ssc[i]=q.top();
		q.pop();
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		my1=my2=my3=0;
		anss=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			vis[i]=0;
			scanf("%d",&la[i][1]);
			scanf("%d",&la[i][2]);
			scanf("%d",&la[i][3]);
			if(la[i][1]>=la[i][2] and la[i][1]>=la[i][3]){
				my1++;
			}else if(la[i][2]>=la[i][1] and la[i][2]>=la[i][3]){
				my2++;
			}else{
				my3++;
			}ssa[i].idd=ssb[i].idd=ssc[i].idd=i;
		}if(my1>=my2 and my1>=my3){
			for(int i=1;i<=n;i++)ssa[i].nm=la[i][1]-max(la[i][2],la[i][3]);
			ast();
			for(int i=1;i<=n/2;i++){
				if(ssa[i].nm<0)break;
				anss+=la[ssa[i].idd][1];
				vis[ssa[i].idd]=1;
			}
			for(int i=1;i<=n;i++){
				if(vis[i]==1)continue;
				anss+=max(la[i][2],la[i][3]);
			}
		}else if(my2>=my3 and my2>=my1){
			for(int i=1;i<=n;i++)ssb[i].nm=la[i][2]-max(la[i][1],la[i][3]);
			bst();
			for(int i=1;i<=n/2;i++){
				if(ssb[i].nm<0)break;
				anss+=la[ssb[i].idd][2];
				vis[ssb[i].idd]=1;
			}
			for(int i=1;i<=n;i++){
				if(vis[i]==1)continue;
				anss+=max(la[i][3],la[i][1]);
			}
		}else{
			for(int i=1;i<=n;i++)ssc[i].nm=la[i][3]-max(la[i][2],la[i][1]);
			cst();
			for(int i=1;i<=n/2;i++){
				if(ssc[i].nm<0)break;
				anss+=la[ssc[i].idd][3];
				vis[ssc[i].idd]=1;
			}
			for(int i=1;i<=n;i++){
				if(vis[i]==1)continue;
				anss+=max(la[i][2],la[i][1]);
			}
		}cout<<anss<<'\n';
	}
	return 0;
} 
