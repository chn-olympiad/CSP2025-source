#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int n,T,a[N][4],sub[N];
long long ans;
bool cmp1 (int x,int y){
	return sub[x]>sub[y];
}

struct pq{
	int t[2*N],siz;
}aa,bb,cc;
void push(int x,int i){
	if(i==1){
		aa.t[++aa.siz]=x;
		int k=aa.siz;
		while(sub[aa.t[k/2]]>sub[x] && k>1){
			swap(aa.t[k/2],aa.t[k]);
			k=k>>1;
		}
		return;
	}
	if(i==2){
		bb.t[++bb.siz]=x;
		int k=bb.siz;
		while(sub[bb.t[k/2]]>sub[x] && k>1){
			swap(bb.t[k/2],bb.t[k]);
			k=k>>1;
		}
		return;
	}
	if(i==3){
		cc.t[++cc.siz]=x;
		int k=cc.siz;
		while(sub[cc.t[k/2]]>sub[x] && k>1){
			swap(cc.t[k/2],cc.t[k]);
			k=k>>1;
		}
		return;
	}
	return;
}
void df(int x,int i){
	if(i==1){
		int k=x,l,r;
		l=k<<1;r=(k<<1)+1;
		if(l>aa.siz||(sub[aa.t[k]]<sub[aa.t[l]]&&sub[aa.t[k]]<sub[aa.t[r]]))return;
		if(r>aa.siz||sub[aa.t[l]]<sub[aa.t[r]]){
			swap(aa.t[l],aa.t[k]);
			df(l,1);
			return;
		}
		swap(aa.t[r],aa.t[k]);
		df(r,1);
		return;
	}
	if(i==2){
		int k=x,l,r;
		l=k<<1;r=(k<<1)+1;
		if(l>bb.siz||(sub[bb.t[k]]<sub[bb.t[l]]&&sub[bb.t[k]]<sub[bb.t[r]]))return;
		if(r>bb.siz||sub[bb.t[l]]<sub[bb.t[r]]){
			swap(bb.t[l],bb.t[k]);
			df(l,1);
			return;
		}
		swap(bb.t[r],bb.t[k]);
		df(r,2);
		return;
	}
	if(i==3){
		int k=x,l,r;
		l=k<<1;r=(k<<1)+1;
		if(l>cc.siz||(sub[cc.t[k]]<sub[cc.t[l]]&&sub[cc.t[k]]<sub[cc.t[r]]))return;
		if(r>cc.siz||sub[cc.t[l]]<sub[cc.t[r]]){
			swap(cc.t[l],cc.t[k]);
			df(l,1);
			return;
		}
		swap(cc.t[r],cc.t[k]);
		df(r,3);
		return;
	}
}
void pop(int i){
	if(i==1){
		aa.t[1]=aa.t[aa.siz];
		aa.siz--;
		df(1,1);
		return;
	}
	if(i==2){
		bb.t[1]=bb.t[bb.siz];
		bb.siz--;
		df(1,2);
		return;
	}
	if(i==3){
		cc.t[1]=cc.t[cc.siz];
		cc.siz--;
		df(1,3);
		return;
	}
	return;
}
void su(int i,int x,int y ){
	sub[i]=a[i][x]-a[i][y];
	return;
}	
void pus( int  i){
	if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
		if(aa.siz==0||aa.siz<(n>>1)){
			//cout<<i;
			push(i,1);
			return;
		}
		else{
			int x=aa.t[1];
			if(sub[i]>sub[x]){
				push(i,1);
				pop(1);
				a[x][1]=-1;
				pus(x);
				return;
			}
		}	
	}
	if(a[i][2]>=a[i][3]){
		if(bb.siz==0||bb.siz<(n>>1)){
				//cout<<i;
			push(i,2);
			return;
		}
		else{
			int x=bb.t[1];
			if(sub[i]>sub[x]){
				push(i,2);
				pop(2);
				a[x][2]=-1;
				pus(x);
				return;
			}
		}	
	}
	if(cc.siz==0||cc.siz<(n>>1)){
			//cout<<i;
		push(i,3);
		return;
	}
	else{
		int x=cc.t[1];
		if(sub[i]>sub[x]){
			push(i,3);
			pop(3);
			a[x][3]=-1;
			pus(x);
			return;
		}
	}	
	return;
}
int main(){
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=0;
		aa.siz=bb.siz=cc.siz=0;
		for(int i=1;i<=n;i++)scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
		for(int i=1;i<=n;i++){
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				if(a[i][2]>a[i][3])su(i,1,2);
				else su(i,1,3);
			}
			else if(a[i][2]>a[i][3]){
				if(a[i][1]>a[i][3])su(i,2,1);
				else su(i,2,3);
			}
			else{
				if(a[i][1]>a[i][2])su(i,3,1);
				else su(i,3,2);
			}
		}
		for(int i=1;i<=n;i++){
			pus(i);
		}
		for(int i=1;i<=aa.siz;i++){
			ans+=a[aa.t[i]][1];
		}
		for(int i=1;i<=bb.siz;i++){
			ans+=a[bb.t[i]][2];
		}
		for(int i=1;i<=cc.siz;i++){
			ans+=a[cc.t[i]][3];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
