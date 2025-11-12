#include<bits/stdc++.h>

using namespace std;

int T,n;
int a[100010],b[100010],c[100010];

bool cmp(int a,int b){
	if(a<b){
		return false;
	}
	return true;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int ren=n/2;
		for(int i=1;i<=100000;i++){
			a[i]=0;
			b[i]=0;
			c[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n==2){
			int res=0;
			res=max(res,a[1]+b[1]);
			res=max(res,a[1]+c[1]);
			res=max(res,a[1]+b[2]);
			res=max(res,a[1]+c[2]);
			
			res=max(res,a[2]+b[1]);
			res=max(res,a[2]+c[1]);
			res=max(res,a[2]+b[2]);
			res=max(res,a[2]+c[2]);
			cout<<res<<endl;
		}else{
			long long res=0;
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				res+=a[i];
			}
			cout<<res<<endl;
		}
	}
	return 0;
}

