#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[4][100004];
int anss;

struct situ{
	int ans,ma,mb,mc;  
};
situ f[4][100004];
void solve(int ren,int man,int aren,int bren,int cren){
	if(ren==n+1){
		anss=max(anss,man);
		return ;
	}
	
	if(aren*2<n){
		solve(ren+1,man+a[1][ren],aren+1,bren,cren);
	}
	if(bren*2<n){
		solve(ren+1,man+a[2][ren],aren,bren+1,cren);
	}
	if(cren*2<n){
		solve(ren+1,man+a[3][ren],aren,bren,cren+1);
	}
}

void unit(){
	anss=0;
	solve(1,0,0,0,0);
	cout<<anss<<endl;
}

void unit2(){

	for(int i=1;i*2<=n;i++){
		f[1][i].ans=f[1][i-1].ans+a[1][i];
		f[1][i].ma=i;
	}
	if(a[1][1]>a[2][1]){
		f[2][1].ans=a[1][1];
		f[2][1].ma=1;
	}else{
		f[2][1].ans=a[2][1];
		f[2][1].mb=1;
	}
	for(int i=2;i<=n;i++){
		if(a[2][i]>a[1][i]){
			f[2][i].ans=f[2][i-1].ans+a[2][i];
			f[2][i].mb++;
		}else{
			f[2][i].ans=f[2][i-1].ans+a[1][i];
			f[2][i].ma++;
		}
	}
	cout<<f[2][n].ans;
	
}

int tt[600];
void unit3(){
	memset(tt,0,sizeof(tt));
	int cnt=0;
	for(int i=1;i<=n;i++){
		tt[i]=a[1][i];
	}
	sort(tt+1,tt+n+1);
	for(int i=n;i>n/2;i--){
		cnt+=tt[i];
	}
	cout<<cnt;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int ii=0;ii<t;ii++){
		cin>>n;
		bool flag3,flag2=true;
		flag3=flag2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[j][i];
				if(j==2 && a[i][j]!=0){
					flag2=false;
				}
				if(j==3 && a[i][j]!=0){
					flag3=false;
				}
				
			}
		}
		
		if(flag3&&flag2){
			unit3();
			continue;
		}
		if(n<=20){
			unit();
			continue;
		}
		if(flag2){
			unit2();
			continue;
		}

	}
	return 0;
}
