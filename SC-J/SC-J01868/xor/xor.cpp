#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int a[N],ans=0;
map<pair<int,int>,int int> mp;
bool f[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(mp[{i,j-1}]!=0)
				mp[{i,j}]=mp[{i,j-1}]^a[j];
			else 
				mp[{i,j}]=a[j];
			if(mp[{i,j}]==k){
				bool fl=0;
				for(int k=i;k<=j;k++)
					if(f[k]==1)
						fl=1;
				if(fl!=1){
					for(int k=i;k<=j;k++) f[k]=1;
					ans++;
					break;
				}
			}
		} 
	} 
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}