#include<bits\stdc++.h>
#include<algorithm>
using namespace std;
const int N=1e7;
int t,n[5],i1[5][100001],i2[5][100001],i3[5][100001],ans[5],a1[5],a2[5],a3[5];
int fro(int t,int x){
		if(i1[t][x]>=max(i2[t][x],i3[t][x]) && a1[t]<n[t]/2 && ans[t]+i1[t][x-1]<=ans[t]+i1[t][x]){
			a1[t]++;
			ans[t]+=i1[t][x];
			return 0;
		}
		else if(i2[t][x]>=i3[t][x] && a2[t]<n[t]/2 && ans[t]+i2[t][x-1]<=ans[t]+i2[t][x]){
			a2[t]++;
			ans[t]+=i2[t][x];
			return 0;
		}
		else{
			a3[t]++;
			ans[t]+=i3[t][x];
			return 0;
		}
		if(i2[t][x]>=max(i1[t][x],i3[t][x]) && a2[t]<n[t]/2 && ans[t]+i2[t][x-1]<=ans[t]+i2[t][x]){
			a2[t]++;
			ans[t]+=i2[t][x];
			return 0;
		}
		else if(i1[t][x]>=i3[t][x] && a1[t]<n[t]/2 && ans[t]+i1[t][x-1]<=ans[t]+i1[t][x]){
			a1[t]++;
			ans[t]+=i1[t][x];
			return 0;
		}
		else{
			a3[t]++;
			ans[t]+=i3[t][x];
			return 0;
		}
		if(i3[t][x]>=max(i1[t][x],i2[t][x]) && a3[t]<n[t]/2 && ans[t]+i3[t][x-1]<=ans[t]+i3[t][x]){
			a3[t]++;
			ans[t]+=i3[t][x];
			return 0;
		}
		else if(i2[t][x]>=i1[t][x] && a2[t]<n[t]/2 && ans[t]+i2[t][x-1]<=ans[t]+i2[t][x]){
			a2[t]++;
			ans[t]+=i2[t][x];
			return 0;
		}
		else{
			a1[t]++;
			ans[t]+=i1[t][x];
			return 0;
		}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int m=0;m<t;m++){
		cin>>n[m];
		for(int i=0;i<n[m];i++)  
		cin>>i1[m][i]>>i2[m][i]>>i3[m][i];
	}
	for(int i=0;i<t;i++) 
	for(int j=0;j<n[i];j++)
	fro(i,j);
	for(int i=0;i<t;i++) cout<<ans[i];
	return 0;
}
