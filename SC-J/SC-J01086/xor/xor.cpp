#include<bits/stdc++.h>
using namespace std;
//RP++
int n,k,a[1145141],sum[1145141],idx,ans=0,visit[10000000];
pair<int,int> c[10000000];
void solve(int x){
	int res=0,flag=n;
	for(int l=1;l+x-1<=flag;l++){
		int tl=l,r=tl+x-1;
		while(r<=n){
			if((sum[r]^sum[tl-1])!=k){
				r++;
				if(tl==l) l++;
				tl++;
			}
			else{
				c[idx++]={tl,r};
				tl=r+1;
				r+=x;
				if(r>n) break;
				if(flag==n)flag=l;
			}
		}
	}
}
int cmp(pair<int,int> a,pair<int,int> b){
	return (a.first==b.first?a.second<b.second:a.first<b.first);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(sum[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	sort(c,c+idx,cmp);
	for(int i=0;c[i].first<=c[0].second&&i<idx;i++){
		int flag=i,cnt=1,cnt2=1;
		stack<int> tmp;
		tmp.push(i);
		for(int j=i+1;j<idx;j++){
			//cout<<j<<" "<<c[j].first<<" "<<c[flag].second<<endl;
			if(c[j].first>c[flag].second){
				if(visit[j]){
					ans=max(visit[j]+cnt,ans);
					flag=j;
					break;
				}
				cnt++;
				flag=j;
				tmp.push(j);
			}
		}
		if(visit[flag]){
			cnt2=visit[flag]+1;
		}
		while(!tmp.empty()){
			visit[tmp.top()]=cnt2++;
			tmp.pop();
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
