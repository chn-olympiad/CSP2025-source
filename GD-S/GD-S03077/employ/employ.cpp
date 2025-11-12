#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,k,c[510],a[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k;bool fl=1;
	for(int i=1;i<=n;i++){
		scanf("%1d",&a[i]);
		if(a[i]==0)fl=0;
	}for(int i=1;i<=n;i++)cin>>c[i];
	int res=0;
	if(n<=10){
		int p[11]={0,1,2,3,4,5,6,7,8,9,10};
		do{
			int now=0;
			for(int i=1;i<=n;i++){
				if(c[p[i]]<=now)now++;
				else if(a[i]==0)now++;
			}res+=((n-now)>=k);
		}while(next_permutation(p+1,p+1+n));
		cout<<res;
	}else if(n<=18){
		
	}
	return 0;
}
