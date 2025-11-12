#include<cstdio>
//#include<algorithm>

#define ll long long
//#define int long long
using namespace std;
int list[500100]={};
int cal [500100]={};
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	bool part;
	for(int i=0;i<n;i++){
		scanf("%d",list+i);
		if(list[i]>1)part=0;
	}
	if(!part){
		int ret=0;
		int l=0;
		for(int r=0;r<n;r++){
			for(int i=l;i<=r;i++){
				cal[i]^=list[r];
				if(cal[i]==k){
					l=r+1;
					ret++;break;
				}
			}
		}
		printf("%d",ret);
	}else{
		int ret=0;
		for(int i=0;i<n;i++){
			if(list[i]==1){
				ret++;
			}
		}
		printf("%d",ret);
	}
}
