#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,sum[500005];
bool m[1005][1005];
long long ans;
struct edge{
	int l,r;
}e[1000005];
bool cmp(edge x,edge y){
	if(x.l==y.l){
		return x.r<y.r;
	}
	else{
		return x.l<y.r;
	}
}
int main(){
	ifstream r("xor.in");
	ofstream w("xor.out");
	r>>n>>k;
	bool ba,bb;
	for(int i=1;i<=n;i++){
		r>>a[i];
		sum[i]=a[i]^sum[i-1];
		if(a[i]!=1){
			ba=true;
		}
		if(a[i]>1||a[i]<0){
			bb=true;
		}
	}
	if(!ba){
		if(k==1){
			w<<n;
		}
		else{
			w<<n/2;
		}
	}
	else if(!bb){
		int suma=0,sumb=0,judgeb=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				suma++;
				judgeb++;
				if(judgeb%2==0){
					sumb++;
					judgeb=0;
				}
			}
			else{
				sumb++;
				judgeb=0;
			}
		}
		if(k==1){
			w<<suma;
		}
		else{
			w<<sumb;
		}
	}
	else if(n<=1000){
		int len=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(sum[j]-sum[i-1]==k){
					m[i][j]=1;
					len++;
					e[len].l=i;
					e[len].r=j;
				}
			}
		}
		sort(e+1,e+1+len,cmp);
		int i=1,j=1,ans=0;
		while(i<n){
			while(e[j].l<i&&j<=len){
				j++;
			}
			if(j<=len){
				ans++;
				i=e[j].r+1;
			}
			else{
				break;
			}
		}
		w<<ans;
	}
	return 0;
}
