#include <bits/stdc++.h>
using namespace std;
int cnt,n,a[5005],cmp[5005];
bool fan[5005];
void search(int jhy,int xy,int dangqianid,int cpid){
	if(xy>=jhy){
		int sum=0,maxn=-10000;
		for(int i=1;i<=jhy;i++){
			sum+=cmp[i];
			if(cmp[i]>maxn) maxn=cmp[i];
		}
		if(sum>2*maxn){
			cnt++;cnt%=998;cnt%=244;cnt%=353;
		}
		return;
	}
	else {
		for(int i=dangqianid+1;i<=n;i++){
			cmp[cpid+1]=a[i];
			search(jhy,xy+1,i,cpid+1);
			cmp[cpid+1]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	for(int i=3;i<=n;i++){
		search(i,0,0,0);
	}
	cout <<cnt;
	return 0;
} 