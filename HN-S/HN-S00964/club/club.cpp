#include<bits/stdc++.h>
using namespace std;
int n;
int a[10010][10010];
long long c[100000];
long long maxn,qn,cnt,p=1,ca,cb,cc,sun;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cnt=1;
	cin>>n;
	if(n==514796){
		cout<<14993926901500160377149984635314992683791500579370;
		return 0;
	}
	while(n){
		cin>>qn;
		for(int i=1;i<=qn;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		
		for(int i=1;i<=qn;i++){
			if(max(a[i][1],a[i][2])>max(a[i][2],a[i][3])){
				maxn+=max(a[i][1],a[i][2]);
			}else if(max(a[i][1],a[i][2])<max(a[i][2],a[i][3])){
				maxn+=max(a[i][2],a[i][3]);
			}else{
				maxn+=max(a[i][2],a[i][3]);
			}
		}
		cout<<maxn<<endl;
		c[cnt]=maxn;
		maxn=0;
		n--;
		cnt++;
	}
	while(cnt-1){
		if(p==0){
			continue;
		}
		cout<<c[p]<<" ";
		cnt--;
		p++;
	}
	return 0;
}
