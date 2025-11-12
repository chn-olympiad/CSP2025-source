#include<bits/stdc++.h>
using namespace std;
long long a,b[5005],d=0;
void dfs(long long f,long long g,long long k,long long i){
	if(k>=4&&f>(2*g)){
		d++;
		d%=998244353;
	}
	if(i>a)return ;
	for(long long z=i;z<=a;z++){
		dfs(f+b[z],max(g,b[z]),k+1,z+1);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int z=1;z<=a;z++){
		cin>>b[z];
	}
	sort(b+1,b+1+a);
	for(int z=1;z<=a;z++){
		dfs(b[z],b[z],1,z+1);
	}
	cout<<d%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
