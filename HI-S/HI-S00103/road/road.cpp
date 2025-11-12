#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[100004],aa[100004],c[15],cc[100004],b[100004],bb[14];
int dfs(int d,int money,int mub){
	if(mub==n) return money;
	return dfs(a[d],money+aa[d],mub+1);
}
int ddfs(int money,int at){
	cc[at]=1;
	if(a[at]!=0&&b[at]!=0&&cc[a[at]]==0&&cc[b[at]]==0){
		return min(ddfs(money+aa[at],a[at]),ddfs(money+bb[at],b[at]));
	}else if(a[at]!=0&&cc[a[at]]==0){
		return ddfs(money+aa[at],a[at]); 
	}else if(b[at]!=0&&cc[b[at]]==0){
		return ddfs(money+bb[at],b[at]);
	}else{
		return money;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=0;i<m;i++){
			int t,p,mo;
			cin>>t>>p>>mo;
			a[t]=p;b[p]=t;
			bb[p]=mo;
			aa[t]=mo;
		}
		cout<<ddfs(0,0);
		return 0;
	}
	for(int i=0;i<m;i++){
		int d;
		cin>>d;
		cin>>a[d]>>aa[d];
		a[a[d]]=d;
		aa[a[d]]=d;
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		int d[114514]={0};
		for(int j=0;j<n;j++){
			cin>>d[i];
		}
		for(int j=0;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(a[j]==k){
					aa[j]=min(aa[j],d[j]+d[k]);
				}else if(a[k]!=j){
					aa[k]=d[j]+d[k];
					a[k]=j;
				}
			}
		}
	}
	cout<<dfs(1,0,1);
	return 0;
}

