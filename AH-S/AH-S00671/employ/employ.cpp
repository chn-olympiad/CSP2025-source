#include<bits/stdc++.h>
using namespace std;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	string s1;
	cin>>s1;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	sort(c+1,c+1+n);
	if(m==1){
		long long cnt=0,sum=1,su=0;
		for(int i=0;i<n;i++){
			if(s1[i]=='1'){
				su=0;
				for(int j=1;j<=n;j++){
					if(c[j]>cnt){
						su++;
					}
				}
				sum=(sum%998244353+su%998244353)%998244353;
			}
			else if(s1[i]=='0'){
				cnt++;
			}			
		}
		for(int j=2;j<=n-1;j++){
			sum=(sum%998244353*j%998244353)%998244353;
		}
		printf("%lld\n",sum);
	}
	else printf("0\n");
    return 0;
}
