#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k;
int u[N],v[N],w[N];
int c[N],a[15][N];
bool f[N];
bool f1=true;
long long ans;
bool check(){
	for(int i=1;i<=m;i++){
		if(f[i]==false){
			return false;
		}
	}
	return true;
}
void check0(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=i;j++){
			if(w[i]<w[j]) {
				swap(u[i],u[j]);
				swap(v[i],v[j]);
				swap(w[i],w[j]);
			}
		}
	}
	/*
	for(int i=1;i<=m;i++){
		cout<<u[i]<<" "<<v[i]<<" "<<w[i]<<endl;
	}
	*/
	for(int i=1;i<=m;i++){
		if(f[u[i]]==true and f[v[i]]==true) continue;
		f[u[i]]=true;
		f[v[i]]=true;
		ans+=w[i];
		if(check()==true) break;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=i;j++){
			if(w[i]<w[j]) {
				swap(u[i],u[j]);
				swap(v[i],v[j]);
				swap(w[i],w[j]);
			}
		}
	}
	/*
	for(int i=1;i<=m;i++){
		cout<<u[i]<<" "<<v[i]<<" "<<w[i]<<endl;
	}
	*/
	ans+=w[1];
	return;
}
void check1(){
	int min_=INT_MAX;
	for(int i=1;i<=n;i++){
		min_=INT_MAX;
		for(int j=1;j<=k;j++){
			min_=min(min_,a[j][i]);
		}
		ans+=min_;
	}
	return;
}
void check2(){
	long long num=0;
	for(int i=1;i<=k;i++){
		ans+=c[i];
	}
	int min_=INT_MAX;
	for(int i=1;i<=n;i++){
		min_=INT_MAX;
		for(int j=1;j<=k;j++){
			min_=min(min_,a[j][i]);
		}
		ans+=min_;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=i;j++){
			if(w[i]<w[j]) {
				swap(u[i],u[j]);
				swap(v[i],v[j]);
				swap(w[i],w[j]);
			}
		}
	}
	/*
	for(int i=1;i<=m;i++){
		cout<<u[i]<<" "<<v[i]<<" "<<w[i]<<endl;
	}
	*/
	for(int i=1;i<=m;i++){
		if(f[u[i]]==true and f[v[i]]==true) continue;
		f[u[i]]=true;
		f[v[i]]=true;
		num+=w[i];
		if(check()==true) break;
	}
	ans=min(num,ans);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(f,0,sizeof(f));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) f1=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0) {
		check0();
		cout<<ans<<endl;
		return 0;
	}
	if(f1==true) {
		check1();
		cout<<ans<<endl;
		return 0;
	}
	check2();
	cout<<ans<<endl;
	return 0;
}

