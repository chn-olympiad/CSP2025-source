#include<bits/stdc++.h>
using namespace std;
const long long INF=998244353;
long long n,m,cnt,sl,ls;
long long a[1100],b[1100];
char s[1010];
long long ans,Max=1,Ans;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	scanf("%s",s);
	for(int i=0;i<n;i++){
		a[i+1]=s[i]-'0'; 
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&b[i]);
		if(b[i]==0){
			sl++;
			b[i]=n+1;
		}
	}
	ls=n-sl;
	sort(b+1,b+n+1);
	if(m==1){
		for(int i=1;i<=ls;i++){
			ans=1;
			for(int j=1;j<=min(sl,b[i]);j++){				
				if(a[j]==1){
					Max=1;
					for(int k=j;k<=sl;k++){
						Max=(Max*k)%INF; 
					}
					Ans=(Ans+((Max*ans)%INF))%INF;
				}
				ans=(ans*j)%INF;
			}
		}
	}
	cout<<Ans;
	fclose(stdin);
	fclose(stdout);	
	return 0;
}

