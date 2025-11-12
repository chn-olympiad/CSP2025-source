#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int Aa(int nn,int ii){
	int s=1;
	for(int j=nn;j > (nn-ii);j--){
		s*=j;
	}
	return s;
}
int Cc(int nn,int ii){
	return Aa(nn,ii) / Aa(ii,ii);
}
int n;
vector<int>a;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int b=0,zzz,MAx=-114514,MIn=0x3f3f3f3f;
	
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&zzz);
		a.push_back(zzz);
		if(zzz>MAx) MAx=zzz;
		if(zzz<MIn) MIn=zzz;
	}
	int s=0;
	if(MAx< 2*MIn){
		for(int i=3;i<=n;i++){
			s=(s+Cc(n,i))%MOD;
		}
	}else{
		sort(a.begin(),a.end());
		if(n==3){
			if(a[0]+a[1]+a[2]>2*a[2]){
				s=1;
			}
		}else{
			for(int l=3;l<=n;l++){
				s+=a[l-1]+9;
			}
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
