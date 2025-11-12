#include<bits/stdc++.h>
using namespace std;
int n,k,ans,d[500007],s;
int find(vector<int>v,int y){
//	cout<<x<<" "<<y<<endl;
//	for(int i=0;i<v[x].size();i++)cout<<v[x][i]<<endl;
	int l=0,r=v.size()-1,mid,cnt=1e9;
	while(l<=r){
		mid=(l+r)/2;
		if(v[mid]>=y){
			cnt=v[mid];
			r=mid-1;
		}else l=mid+1;
	}
	return cnt;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	vector<vector<int>>v((1<<20)+7);
	v[0].push_back(0);
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		d[i]=d[i-1]^x;
		v[d[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int it=find(v[k^d[i]],s);
//		cout<<i<<" "<<(k^d[i])<<" "<<it<<endl;
		if(it!=1e9&&it<i){
	//		cout<<s+1<<" "<<i<<endl;
			ans++;
			s=i;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
