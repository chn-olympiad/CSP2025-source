#include<bits/stdc++.h>
using namespace std;
int t,n,a1[100005],a2[100005],a3[100005],mx=0;
int conv(int i,int j);
int max1(int i){
	int mxt;
	if(a1[i]>a2[i]) mxt = 0;
	if(a1[i]<a2[i]) mxt = 1;
	if(a2[i]>a3[i]) mxt = 1;
	if(a2[i]<a3[i]) mxt = 2;
	return mxt;
}
int conv(int i,int j){
	switch(j){
		case 0:
		    return a1[i];
		case 1:
		    return a2[i];
		case 2:
		    return a3[i]; 
	}
}
int conv1(int i,int j,int k){
	switch(j){
		case 0:
		    a1[i]=k;
		    return 0;
		case 1:
		    a2[i]=k;
		    return 0;
		case 2:
		    a3[i]=k; 
	}
}
void dfs(int tmp,bool v[],int c1,int c2,int c3,int f,int a){
	if(n==2){
		int cnt[3]={0,0,0},mx1,mx2;
		mx1 = max1(0);
		cnt[mx1]++;
		mx2 = max1(1);
		bool flag=0;
		if(cnt[mx2]==1){
			conv1(1,mx2,-1);
			mx2 = max1(1);
		}
		mx = conv(0,mx1)+conv(1,mx2);
		return;
	}
	if(f==n){
		if(tmp>mx && c1!=0 && c2!=0 && c3!=0) mx=tmp;
		return;
	}
	for(int i=0;i<n;i++){
		if(!v[i]){
			v[i] = 1;
			if(c1<=n/2){
				dfs(tmp+a1[i],v,c1+1,c2,c3,f+1,a+1);
			}
			if(c2<=n/2){
				dfs(tmp+a2[i],v,c1,c2+1,c3,f+1,a+1);
			}
			if(c3<=n/2){
				dfs(tmp+a3[i],v,c1,c2,c3+1,f+1,a+1);
			}
			v[i] = 0;
		}
	} 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int ic=0;ic<t;ic++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		mx = 0;
		bool v[100005]={0};
		dfs(0,v,0,0,0,0,0);
		cout<<mx<<endl;
	}
	return 0;
}