#include<bits/stdc++.h>
using namespace std;
long long t,anss=0,n;
int jssz[50];
struct pkm{
	long long a,b,c,zdc;
}nn[100005];
bool cmpa(pkm oo,pkm uu){
	return oo.zdc<uu.zdc;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		long long anns=0;
		memset(jssz,0,sizeof jssz);
		for(int k=1;k<=n;k++){
			cin>>nn[k].a>>nn[k].b>>nn[k].c;
			if(nn[k].a>=nn[k].b&&nn[k].a>=nn[k].c){
				anns+=nn[k].a;
				jssz[1]++;
				if(nn[k].b>=nn[k].c) nn[k].zdc=nn[k].a-nn[k].b;
				else nn[k].zdc=nn[k].a-nn[k].c;
			}
			else if(nn[k].b>=nn[k].a&&nn[k].b>=nn[k].c){
				anns+=nn[k].b;
				jssz[2]++;
				if(nn[k].a>=nn[k].c) nn[k].zdc=nn[k].b-nn[k].a;
				else nn[k].zdc=nn[k].b-nn[k].c;
			}
			else if(nn[k].c>=nn[k].a&&nn[k].c>=nn[k].b){
				anns+=nn[k].c;
				jssz[3]++;
				if(nn[k].b>=nn[k].a) nn[k].zdc=nn[k].c-nn[k].b;
				else nn[k].zdc=nn[k].c-nn[k].a;
			}
		}
		int kk=n/2;
		int hh=1;
		
		if(jssz[1]>kk){
			sort(nn+1,nn+n+1,cmpa);
			while(jssz[1]>kk){
				if(nn[hh].a<nn[hh].b||nn[hh].a<nn[hh].c){
					hh++;
					continue;
				}
				jssz[1]--;
				anns-=nn[hh].zdc;
				hh++;
			}
			
		}
		if(jssz[2]>kk){
			sort(nn+1,nn+n+1,cmpa);
			while(jssz[2]>kk){
				if(nn[hh].b<nn[hh].a||nn[hh].b<nn[hh].c){
					hh++;
					continue;
				}
				jssz[2]--;
				anns-=nn[hh].zdc;
				hh++;
			}
		}
		if(jssz[3]>kk){
			sort(nn+1,nn+n+1,cmpa);
			while(jssz[3]>kk){
				if(nn[hh].c<nn[hh].b||nn[hh].c<nn[hh].a){
					hh++;
					continue;
				}
				jssz[3]--;
				anns-=nn[hh].zdc;
				hh++;
			}
		}
		cout<<anns<<"\n";
		
	}
	return 0;
	
}
