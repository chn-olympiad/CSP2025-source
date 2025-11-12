#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=1e5+5;
const int NN=4e2+5;
int x,y,z;
int t,n,k;
int flag=0;
struct A{
	int i;
	int a;
	int b;
	int c;
};
int ans=0;
vector<A> numsa,numsb,numsc;
int visn[N];

void dfs(int ca,int cb,int cc,vector<int> vis,int ak,int bk,int ck){
	int k=n/2;
	if(vis.empty()){
		ans=max(ans,ca+cb+cc);
		return;
	}
	if(ak==k&&bk==k&&ck==k){
		ans=max(ans,ca+cb+cc);
		return;
	}
	
	for(int i=0;i<vis.size();i++){
		int tmp=vis[i];
		//for(int i=0;i<vis.size();i++)cout <<vis[i]<<" ";
		//cout <<endl;
		vis.erase(vis.begin()+i);
		if(ak<k)dfs(ca+numsa[tmp].a,cb,cc,vis,ak+1,bk,ck);
		
		if(bk<k)dfs(ca,cb+numsa[tmp].b,cc,vis,ak,bk+1,ck);

		if(ck<k)dfs(ca,cb,cc+numsa[tmp].c,vis,ak,bk,ck+1);
		vis.insert(vis.begin()+i,tmp);
	}
}

bool cmpa(A a,A b){
	return a.a>b.a;
}
bool cmpb(A a,A b){
	return a.b>b.b;
}
bool cmpc(A a,A b){
	return a.c>b.c;
}

void solve2(){
 
	int ak=0,bk=0,ck=0;
	int ca=0,cb=0,cc=0;	
	int ia=0,ib=0,ic=0;
	int cnt=0;
	sort(numsa.begin(),numsa.begin()+n,cmpa);
	if(flag==0){
		for(int i=0;i<k;i++){
			 ca+=numsa[i].a;
		}
		cout <<ca<<endl;
		return;
	}
	sort(numsb.begin(),numsb.begin()+n,cmpb);
	if(flag==1){
	while((ia<k&&ib<k)&&cnt!=n){
		while(visn[numsa[ia].i]==1)ia++;
		while(visn[numsb[ib].i]==1)ib++;
		//while(vis[numsc[ic].i]==1)ic++;
		int cala=ca+numsa[ia].a+cb+cc;
		int calb=ca+cb+numsb[ib].b+cc;
		//int calc=ca+cb+numsc[ic].c+cc;
		if(cala>calb){
			ca+=numsa[ia].a;
			ia++;
			cnt++;
			visn[numsa[ia].i]=1;
		}
		if(cala<calb){
			cb+=numsb[ib].b;
			ib++;
			cnt++;
			visn[numsb[ib].i]=1;
		}
		
		if(cala==calb){
			if(numsa[ia+1].a<numsb[ib+1].b){
				cb+=numsb[ib].b;
				ib++;
				cnt++;
				visn[numsb[ib].i]==1;
			}
			else{
			ca+=numsa[ia].a;
			ia++;
			cnt++;
			visn[numsa[ia].i]==1;	
			}

		}
		
		
	}
	}
	sort(numsc.begin(),numsc.begin()+n,cmpc);

	while((ia<k&&ib<k&&ic<k)&&cnt!=n){
		while(visn[numsa[ia].i]==1)ia++;
		while(visn[numsb[ib].i]==1)ib++;
		while(visn[numsc[ic].i]==1)ic++;
		int cala=ca+numsa[ia].a+cb+cc;
		int calb=ca+cb+numsb[ib].b+cc;
		int calc=ca+cb+numsc[ic].c+cc;
		if(cala>calb&&cala>calc){
			ca+=numsa[ia].a;
			ia++;
			cnt++;
			visn[numsa[ia].i]=1;
		}
		if(cala<calb&&calc<calb){
			cb+=numsb[ib].b;
			ib++;
			cnt++;
			visn[numsb[ib].i]=1;
		}
		if(cala<calc&&calb<calc){
			cc+=numsc[ic].c;
			ic++;
			cnt++;
			visn[numsc[ic].i]=1;
		}
		if(cala==calb){
			ca+=numsa[ia].a;
			ia++;
			cnt++;
			visn[numsa[ia].i]==1;
		}
		
		
	}
	cout <<ca+cb+cc<<endl;

}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	while(t--){
		memset(visn,n,0);
		numsa.clear();
		numsb.clear();
		numsc.clear();
		ans=0;
		vector<int> visb;
		cin >>n;
		k=n/2;
		for(int i=0;i<n;i++){
			cin >>x>>y>>z;
			if(z!=0)flag++;
			if(y!=0)flag++;
			numsa.push_back({i,x,y,z});
			numsb.push_back({i,x,y,z});
			numsc.push_back({i,x,y,z});
			visb.push_back(i);
		}
		if(flag!=0&&flag!=1&&n<=10){
			dfs(0,0,0,visb,0,0,0);
			cout <<ans<<endl;

		}
		else{
			solve2();

		}
				
	}
	return 0;
}
