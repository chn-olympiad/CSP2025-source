#include<bits/stdc++.h>
using namespace std;
int t1[3005];
int vis[3005]={0},m=0;
int ph[3005];
int find_max(int n,int p){
	int Max=0;
	for(int i=1;i<=n;i++){
		if(Max<ph[i]) Max=ph[i];
	}
	if(Max<t1[p]) Max=t1[p];
	return Max;
}
int find_sum(int n){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=ph[i];
	}
	return sum;
}
void Search(int n,int s){
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(s<3){
				s++;
				vis[i]=1;
				ph[s]=t1[i];
				Search(s+1,n-1);
				vis[i]=0;
			}
			else{
				if(find_sum(s)+t1[i]>2*find_max(s,i)){
					m++;
					s++;
					vis[i]=1;
					ph[s]=t1[i];
					Search(s+1,n-1);
					vis[i]=0;
				}
			}
		}	
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t1[i]; 
	}
	Search(n,1);
	cout<<m%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}