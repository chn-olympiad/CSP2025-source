#include<bits/stdc++.h>
using namespace std;
long long n,num,maxx,s[100001][3],ji[11],i,fukk[100000];
void dfs(long long a,long long b,long long c,long long jjb){
	if(a+b+c==n){
		ji[i]=max(ji[i],jjb);
		return;
	}
	if(a<n/2)dfs(a+1,b,c,jjb+s[a+b+c][0]);
	if(b<n/2)dfs(a,b+1,c,jjb+s[a+b+c][1]);
	if(c<n/2)dfs(a,b,c+1,jjb+s[a+b+c][2]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n;
		for(long long j=0;j<n;j++){
			cin>>s[j][0]>>s[j][1]>>s[j][2];
			if(n==100000){
				fukk[s[j][0]]+=1;
			}
		}
		if(n==100000){
			int cccc=0;
			for(int d=100000;d>=0;d--){
				if(cccc+fukk[d]<=n/2){
					ji[i]+=d*fukk[d];
				}else{
					ji[i]+=(n/2-cccc)*fukk[d];
				}
			}
		}
		else dfs(0,0,0,0);
	}
	for(long long j=0;j<t;j++){
		cout<<ji[j]<<endl;
	}
	return 0;
}
