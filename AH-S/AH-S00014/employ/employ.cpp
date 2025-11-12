#include<bits/stdc++.h>
using namespace std;

int n,m;

char dft[111166];

int ptnt[111166];

int can=0;

int No=0;

bool cmp(int a,int b){
	return a<b;
}

int counting=0;

bool vis[1111660];

void dfs(int ndx,int rc[]){
	if(ndx==n){
		No=can=0;
		for(int i=0;i<n;i++){
			if(No>=rc[i]){
				No++;
			}else{
				if(dft[i]=='0'){
					No++;
				}else{
					can++;
				}
			}
		}
		if(can>=m){
			counting++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		rc[ndx]=ptnt[i];
		vis[i]=true;
		dfs(ndx+1,rc);
		vis[i]=false;
	}
	return;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n<=10){
		for(int i=1;i<=n;i++){
			cin>>dft[i];
		}
		for(int i=1;i<=n;i++){
			cin>>ptnt[i];
		}
		int a[111166]={0};
		dfs(0,a);
		cout<<counting;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>dft[i];
	}
	for(int i=1;i<=n;i++){
		cin>>ptnt[i];
		if(ptnt[i]==0){
			ptnt[i]=0x3f3f3f3f;
		}
	}
	sort(ptnt+1,ptnt+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(No>=ptnt[i]){
			No++;
		}else{
			if(dft[i]=='0'){
				No++;
			}else{
				can++;
			}
		}
	}
	if(can<m){
		cout<<0;
		return 0;
	}else if(can==m){
		int cnt=0;
		long long sum=1;
		long long now=1;
		No=0;
		for(int i=1;i<=n;i++){
			can=0;
			if(No>=ptnt[i]){
				can=1;
				No++;
			}else if(dft[i]=='0'){
				No++;
			}
			if(can){
				now=1;
				for(int j=0;j<cnt;j++){
					now=(now*(j+1%998244353))%998244353;
				}
				sum=(sum*now)%998244535;
				cnt=1;
			}else{
				cnt++;
			}
		}
		now=1;
		for(int j=0;j<cnt;j++){
			now=(now*(j+1%998244353))%998244353;
		}
		sum=(sum*now)%998244535;
		cnt=1;
		cout<<sum;
	}else{
		bool especial_A=true;
		int especial_B=0;
		for(int i=1;i<=n;i++){
			if(dft[i]!='1'){
				especial_A=false;
			}
			if(dft[i]=='1'){
				especial_B++;
			}
		}
		if(especial_A){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(ptnt[i]!=0){
					cnt++;
				}
			}
			if(cnt<m){
				cout<<0;
			}else{
				long long sum=1;
				for(int i=1;i<=cnt;i++){
					sum=(sum*i)%998244353;
				}
				cout<<sum;
				return 0;
			}
		}
	}
	return 0;
}
