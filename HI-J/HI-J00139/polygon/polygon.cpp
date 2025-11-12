#include<bits/stdc++.h>
using namespace std;
struct t{
	int ii,cnt,maxx,gs;
};
int aa[5100];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&aa[i]);
	}
	queue<t> q;
	for(int i=1;i<=n-2;i++){
		for(int l=i+1;l<=n-1;l++){
			q.push({l,(aa[i]+aa[l]),max(aa[i],aa[l]),2});
		}
	}
	int cntt=0;
	while(!q.empty()){
		t z=q.front();
		q.pop();
		if(z.gs>=3&&z.cnt>z.maxx*2){
			cntt++;
			cntt%=998244353;
		}
		for(int i=z.ii +1;i<=n;i++){
			int ma=max(z.maxx ,aa[i]);
			q.push({i,(z.cnt +aa[i]),ma,(z.gs +1)});
		}
	}
	printf("%d",cntt);
	return 0;
}
