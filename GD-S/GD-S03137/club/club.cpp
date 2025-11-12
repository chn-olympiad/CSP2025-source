#include<bits/stdc++.h>
using namespace std;
int t,n,ans=0;
const int MS=1e5+10;
map<int,int> mp;
struct score{
	int value,id;
};
bool cmp(score a,score b){
	return a.value>b.value;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		ans=0;
		score a[MS],b[MS],c[MS];
		for(int j=1;j<=n;j++){
			a[i].id=b[i].id=c[i].id=i;
			cin>>a[i].value>>b[i].value>>c[i].value;
			sort(a+1,a+n+1,cmp);
			sort(b+1,b+n+1,cmp);
			sort(c+1,c+n+1,cmp);
			int max_=max(max(a[i].value,b[i].value),c[i].value);
			if(max_=a[i].value&&mp[a[i].id]==0){
				mp[a[i].id]=1;
				ans+=a[i].value;
			}
			else if(max_=b[i].value&&mp[b[i].id]==0){
				mp[b[i].id]=1;
				ans+=b[i].value;
			}
			else if(max_=c[i].value&&mp[c[i].id]==0){
				mp[c[i].id]=1;
				ans+=c[i].value;
			}
		}
		
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
