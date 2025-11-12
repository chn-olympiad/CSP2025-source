#include <bits/stdc++.h>
using namespace std;
long long t,n,cnt[5]={0},ans=0,ccnt=0;
long long a[100010][4],b[100010];
void dfs(long long k,long long an){
	long long i;
	if(k==n+1){
	if(an>ans) ans=an;	
	}
	else
	for(i=1;i<=3;i++){
		if(cnt[i]<(n/2)){
		cnt[i]++;
		dfs(k+1,an+a[k][i]);	
		cnt[i]--;
		}
	}
}
int main(){
	long long i,j;
	ifstream fin("club.in");
	ofstream fout("club.out");
	fin>>t;
	for(i=1;i<=t;i++){
		fin>>n;
		ans=0;
		if(n<1000){
			for(j=1;j<=n;j++) fin>>a[j][1]>>a[j][2]>>a[j][3];
			dfs(1,0);
			fout<<ans<<endl;
			for(j=1;j<=3;j++) cnt[j]=0;
			ans=0;
		}
		else{
			int oo,uu;
			for(j=1;j<=n;j++) fin>>b[j]>>oo>>uu;
			sort(b+1,b+1+n);
			for(j=1;j<=n/2;j++) ans+=b[j];
			fout<<ans<<endl;
		}
}
fin.close();
fout.close();
return 0;
}



