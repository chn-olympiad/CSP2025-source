#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
long long a[6000];
long long minn,temp;
void dfs(long long index,long long maxn,long long l){
	if(l>maxn*2&&index>=3){
		ans++;
		cout<<maxn<<" "<<l<<endl;
	}
	if(index==n) return;
	for(long long i=1;i<5005;i++) if(a[i]!=0){
		a[i]--;
		dfs(index+1,max(maxn,i),l+i);
		a[i]++;
	}return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freoprn("polygon.out","w",stdout);
	cin>>n;
	cin>>minn;a[minn]++;temp+=minn;cin>>minn;a[minn]++;temp+=minn;cin>>minn;a[minn]++;temp+=minn;
	for(int i=3;i<n;i++){
		int m;
		cin>>m;
		a[m]++;
	}
	dfs(3,minn,temp);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
