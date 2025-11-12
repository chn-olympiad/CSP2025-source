#include<bits/stdc++.h>
#define int long long 
using namespace std;

int read(){
	int ans=0,d=getchar();
	bool f=0;
	for(;!isdigit(d);d=getchar()) f=(d=='-');
	for(;isdigit(d);d=getchar()) ans=ans*10+d-'0';
	return f ? -ans : ans;
}
const int N=1e5+10;
int t,n;
int a[N][4];
int num;
int b[N];

bool cmp(int a,int b){
	return a>b;
}

signed main(){
	
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	
	t=read();
	while(t--){
		int ans=0;
		n=read();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=read();
				b[i]=a[i][1];
			}
		}
		if(n==100000){
			bool flag=false;
			bool flg=false;
			for(int i=1;i<=n;i++){
				if(a[i][2]!=0&&a[i][3]!=0) flag=true;
			}
			if(flag==false){
				sort(b+1,b+1+n,cmp);
				for(int i=1;i<=n/2;i++){
					ans+=b[i];
				}
			}
		}
		printf("%lld",ans); 
	}
	return 0;
}

