#include<bits/stdc++.h>
using namespace std;
long long sum,n;
struct people{
	int a[4];
	int sum[4];
}p[100005];
bool cmp(people a,people b){
	return a.a[1]>b.a[1];
}
bool cmp2(people a,people b){
	return a.a[2]>b.a[2];
}
bool cmp3(people a,people b){
	return a.a[3]>b.a[3];
}
long long aa[4];
void dfs(int l,int o){
	//cout<<"o="<<o<<endl;
	if(l==n+1){
		if(o>sum){
			sum=o;
		}
	}
	for(int i=1;i<=3;i++){
		if(aa[p[l].sum[i]]==0){
			continue;
		}
		//cout<<"p["<<l<<"]="<<p[l].a[i]<<endl;
		aa[p[l].sum[i]]--;
		dfs(l+1,o+p[l].a[i]);
		aa[p[l].sum[i]]++;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				p[i].sum[j]=j;
			}
			cin>>p[i].a[1]>>p[i].a[2]>>p[i].a[3];
			if(p[i].a[1]<p[i].a[2])swap(p[i].a[1],p[i].a[2]),swap(p[i].sum[1],p[i].sum[2]);
			if(p[i].a[2]<p[i].a[3])swap(p[i].a[2],p[i].a[3]),swap(p[i].sum[2],p[i].sum[3]);
			if(p[i].a[1]<p[i].a[2])swap(p[i].a[1],p[i].a[2]),swap(p[i].sum[1],p[i].sum[2]);
		}
		sort(p+1,p+n+1,cmp);
		/*
		for(int i=1;i<=n;i++){
			cout<<p[i].a[1]<<" "<<p[i].a[2]<<" "<<p[i].a[3]<<"-"<<p[i].sum[1]<<" "<<p[i].sum[2]<<" "<<p[i].sum[3]<<endl;
		}*/
		for(int i=1;i<=3;i++){
			aa[i]=n/2;
		}
		dfs(1,0);
		cout<<sum<<endl;
	}
	return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
