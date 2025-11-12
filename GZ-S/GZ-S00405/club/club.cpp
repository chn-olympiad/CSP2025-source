#include<bits/stdc++.h>//GZ-S00405 裘滨溪 贵州省丘成桐少年班 
using namespace std;
struct mystruct{
	int val1,val2,idx;
};
bool cmp(mystruct a,mystruct b){
	if(a.val1==b.val1){
		return a.val2<b.val2;
	}
	return a.val1>b.val1;
}
int a[100010][5];
int val1,val2,val3;
int n;
int ans;
void dfs(int idx,int sum){
	//cout<<idx<<" ";
	if(idx>n){
		ans=max(ans,sum);
		return;
	}
	if(val1<n/2){
		val1++;
		dfs(idx+1,sum+a[idx][1]);
		val1--;
	}
	if(val2<n/2){
		val2++;
		dfs(idx+1,sum+a[idx][2]);
		val2--;
	}
	if(val3<n/2){
		val3++;
		dfs(idx+1,sum+a[idx][3]);
		val3--;
	}
}
void work(){
	cin>>n;
	bool f1=true,f2=true;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(j==2 && a[i][j]!=0){
				f1=false;
			}
			if(j==3 && a[i][j]!=0){
				f1=f2=false;
			}
		}
	}
	if(f1){
		vector<int> aa;
		for(int i=1;i<=n;i++){
			aa.push_back(a[i][1]);
		}
		sort(aa.begin(),aa.end());
		ans=0;
		for(int i=n-1;i>=n/2;i--){
			ans+=aa[i];
		}
		cout<<ans<<endl;
		return;
	}
	if(f2){
		vector<mystruct> aa,bb;
		for(int i=1;i<=n;i++){
			aa.push_back({a[i][1],a[i][2],i});
			bb.push_back({a[i][2],a[i][1],i});
		}
		sort(aa.begin(),aa.end(),cmp);
		sort(bb.begin(),bb.end(),cmp);
		int sum1=0,sum2=0;
		for(int i=0;i<n/2;i++){
			sum1+=aa[i].val1;
		}
		for(int i=n/2;i<n;i++){
			sum1+=aa[i].val2;
		}
		for(int i=0;i<n/2;i++){
			sum2+=bb[i].val1;
		}
		for(int i=n/2;i<n;i++){
			sum2+=bb[i].val2;
		}
		cout<<max(sum1,sum2)<<endl;
		return;
	}
	if(n<=10){
		val1=val2=val3=ans=0;
		dfs(1,0);
		cout<<ans<<endl;
		return;
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		work();
	}
	return 0;
}
