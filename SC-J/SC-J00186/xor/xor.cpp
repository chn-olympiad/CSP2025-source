#include<bits/stdc++.h>
using namespace std;
long long a[500005],x[500005],p[500005],d[500005],n,k,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=i;j++){
			if(p[j])continue;
			x[j]=x[j]^a[i];
			if(x[j]==k)p[j]=i;}}
	for(int i=1;i<=n;i++){
		if(p[i]==0)continue;
		for(int j=i+1;j<=p[i];j++)
			if(p[j])
				d[i]++,d[j]++;}
	for(int i=1;i<=n;i++){
		if(p[i]==0||d[i]==0)continue;
		for(int j=i+1;j<=p[i];j++){
			if(d[i]>d[j]){
				p[i]=0;
				break;}
			else p[j]=0;}}
	for(int i=1;i<=n;i++)if(p[i])ans++;
	cout<<ans;
	return 0;}