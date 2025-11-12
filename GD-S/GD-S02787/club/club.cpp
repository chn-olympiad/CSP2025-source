#include<bits/stdc++.h>

using namespace std;

#define cin fin
#define cout fout

const int N=1e5+9;

struct per{
	int po,xu;
};

int t,n;

long long ans=0;

per cha[N];
int num[4];

bool cmp(per aa,per bb){
	return aa.po<bb.po;
}

int main(){
	ifstream fin("club.in");
	ofstream fout("club.out");
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		num[1]=0;
		num[2]=0;
		num[3]=0;
		//memset(cha,0,sizeof(cha));
		for(int i=1;i<=n;++i){
			per x,y,z;
			cin>>x.po>>y.po>>z.po;
			x.xu=1;y.xu=2;z.xu=3;
			if(x.po<y.po) swap(x,y);
			if(x.po<z.po) swap(x,z);
			if(y.po<z.po) swap(y,z);
			ans+=x.po;
			++num[x.xu];
			cha[i].po=x.po-y.po;
			cha[i].xu=x.xu;
		}
		int ma=-1;
		int maxu=-1;
		int ha=n/2;
		for(int p=1;p<=3;++p){
			if(ma<num[p]){
				ma=num[p];
				maxu=p;
			}
		}
		if(ma<=ha){
			cout<<ans<<'\n';
		}
		else{
			sort(cha+1,cha+1+n,cmp);
			int k=ma-ha;
			for(int j=1;j<=n&&k>0;++j){
				if(cha[j].xu==maxu){
					--k;
					ans-=cha[j].po;
				}
			}
			cout<<ans<<'\n';
		}
	}
	fin.close();
	fout.close();
	return 0;
}
