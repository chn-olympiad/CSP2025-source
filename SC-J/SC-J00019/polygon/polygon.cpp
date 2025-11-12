#include<bits/stdc++.h>
using namespace std;
int n,a[5005],max_n=0,cnt=0;
bool b[5005];
const int N=998244353;
void dfs(int x,int c,bool b){
	if(x==n or c>n) return;
	for(int i=x;i<n;i++){
		max_n+=a[i];
		if(b){
			if(max_n>a[i]*2)
				cnt++;
			else
				return;
		}
		if(c<3){
			dfs(i+1,c+1,0);
		}else{
			if(max_n>a[i]*2){
				cnt++;
				dfs(i+1,c+1,1);
			}else{
				dfs(i+1,c+1,1);
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n-1);
	dfs(0,0,0);
	cout<<cnt%N;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
