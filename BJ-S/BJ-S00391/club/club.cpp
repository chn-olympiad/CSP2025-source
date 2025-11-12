#include <bits/stdc++.h>
using namespace std;
struct ne{
	long long sv[3];
	long long c;
	int bj;
	bool friend operator <(ne a,ne b){
		return a.c<b.c;
	}
}l[100050];
int maxn(ne s){
	int num=0;
	long long maxnum=0;
	for(int xs=0;xs<3;xs++){
		if(s.sv[xs]>maxnum){
			maxnum=s.sv[xs];
			num=xs;
		}
	}
	return num;
}
int semax(ne s){
	if(max(s.sv[0],s.sv[1])<s.sv[2]){
		if(s.sv[0]<s.sv[1])return 1;
		else return 0;
	}else{
		long long minn;
		int bh;
		if(s.sv[0]>s.sv[1]){
			minn=s.sv[1];
			bh=1;
		}else{
			minn=s.sv[0];
			bh=0;
		}
		if(minn>s.sv[2]){
			return bh;
		}else{
			return 2;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long ans=0;
		int num[3]={};
		for(int xs=1;xs<=n;xs++){
			scanf("%lld%lld%lld",&l[xs].sv[0],&l[xs].sv[1],&l[xs].sv[2]);
			ans+=l[xs].sv[maxn(l[xs])];
			l[xs].c=l[xs].sv[maxn(l[xs])]-l[xs].sv[semax(l[xs])];
			num[maxn(l[xs])]++;
			l[xs].bj=maxn(l[xs]);
		}
		int maxnum=max(num[0],max(num[1],num[2]));
		if(maxnum<=n/2){
			cout<<ans<<endl;
		}else{
			sort(l+1,l+1+n);
			int maxb;
			if(num[0]==maxnum){
				maxb=0;
			}else if(num[1]==maxnum){
				maxb=1;
			}else{
				maxb=2;
			}
			for(int xs=1;xs<=n;xs++){
				if(l[xs].bj==maxb){
					ans-=l[xs].c;
					maxnum--;
					if(maxnum<=n/2){
						break;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
