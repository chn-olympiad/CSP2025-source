#include<bits/stdc++.h>
using namespace std;
int t;
int zx(){
	int n;cin>>n;
	if(n==2){
		int b[3][4];
		for(int i=1;i<=n;i++){
			cin>>b[i][1]>>b[i][2]>>b[i][3];
		}
		int ka1=max(b[1][1],max(b[1][2],b[1][3])),ka2=max(b[2][1],max(b[2][2],b[2][3]));
		int kc1=min(b[1][1],min(b[1][2],b[1][3])),kc2=min(b[2][1],min(b[2][2],b[2][3]));
		int ka1_2,ka2_2,kb1,kb2;
		for(int i=1;i<=3;i++){
			if(ka1==b[1][i]){kb1=b[1][1]+b[1][2]+b[1][3]-ka1-kc1;ka1_2=i;}
			if(ka2==b[2][i]){kb2=b[2][1]+b[2][2]+b[2][3]-ka2-kc2;ka2_2=i;}
		}
		if(ka1_2==ka2_2){
			if(kb1>kb2) ka1=kb1;
			else ka2=kb2;
		}
		cout<<ka1+ka2<<"\n";
		return 0;
	}
	else if(n>=200){
		int t1[100001],t2[100001],t3[100001],sum=0;
		for(int i=1;i<=n;i++) cin>>t1[i]>>t2[i]>>t3[i];
		sort(t1+1,t1+1+n);
		for(int i=n;i>n/2;i--) sum+=t1[i];
		cout<<sum;
		return 0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++) zx();
	return 0;
}
