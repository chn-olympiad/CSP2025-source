#include<bits/stdc++.h>
using namespace std;
int n,T,t,res;
int a[500005][3];
long long s;
vector<pair<int,int> > q[6][3];
int comp(int x,int y,int z){
	if(x>y && x>z){
		return 0;
	}else if(y>x && y>z){
		return 1;
	}
	return 2;
}
int check(){
	if(q[T][0].size()>n/2){
		return 0;
	}
	if(q[T][1].size()>n/2){
		return 1;
	}
	if(q[T][2].size()>n/2){
		return 2;
	}
	return 111;
}
int tz(int res){
	int ans=1e9;
	int idx=0;
	int fi,se;
	for(int i=0;i<q[T][res].size();i++){
		fi=q[T][res][i].first;
		se=q[T][res][i].second;
		int fe=a[se][comp(a[se][0],a[se][1],a[se][2])];
		if(fi-fe<ans){
			idx=i;
			ans=fi-fe;
		}
	}
	swap(q[T][res][idx],q[T][res][q[T][res].size()-1]);
	q[T][res].pop_back();
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	t=T;
	for(T=0;T<t;T++){
		s=0;
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			int ans=comp(a[i][0],a[i][1],a[i][2]);
			q[T][ans].push_back({a[i][ans],i});
			s+=a[i][ans];
			a[i][ans]=0;
		}
		res=check();
		if(res==111){
			printf("%d\n",s);
			continue;
		}
		while(check()!=111){
			s-=tz(res);
		}
		printf("%d\n",s);
	}
	return 0;
} 
