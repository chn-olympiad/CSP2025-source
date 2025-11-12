#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
int n;
int e[5500];
long long q[5500],ok,ans,ansk,mx;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&e[i]);
	}
	sort(e+1,e+n+1);
	q[e[1]]++;q[e[2]]++;
	if(e[1]+e[2]>5000){
		ok++;
	}else{
		q[e[1]+e[2]]++;
	}
	mx=min(5000,e[1]+e[2]);
	for(int i=3;i<=n;i++){
		ansk=0;
		for(int j=e[i]+1;j<=5000;j++){
			if(q[j]!=0){
				ansk+=q[j];
			    ansk%=M;
			} 
		}
		ans+=ansk;ans%=M;
		for(int j=5000;j>=1;j--){
			if(q[j]!=0&&j+e[i]>5000){
				ok+=q[j];
				ok%=M;
			}else if(q[j]!=0){
				q[j+e[i]]+=q[j];
				q[j+e[i]]%=M;
			}
	    }
	    q[e[i]]++;
	    if(mx+e[i]<=5000) mx+=e[i];
	}
	cout<<ans%M;
	return 0;
} 
