#include<bits/stdc++.h>
using namespace std;
long long T,n,a[100005],b[100005],c[100005],ans,maxn,b1,c1;
void add(int i,int aa,int bb,int cc,long long sum){
	if(i>n){
		maxn=max(maxn,sum);
		return ;
	}
	if(aa<ans){
		add(i+1,aa+1,bb,cc,sum+a[i]);
	}
	if(bb<ans){
		add(i+1,aa,bb+1,cc,sum+b[i]);
	}
	if(cc<ans&&c1==1){
		add(i+1,aa,bb,cc+1,sum+c[i]);
	}
	return ;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cin>>n;
		ans=n/2;
		maxn=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0) b1=1;
			if(c[i]!=0) c1=1;
		}
		if(b1==0){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				maxn+=a[i];
			}
			cout<<maxn<<endl;
			continue;
		}
		add(1,0,0,0,0);
		cout<<maxn<<endl;
	}
    return 0;
}

