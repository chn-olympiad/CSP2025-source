#include<bits/stdc++.h>
using namespace std;
vector<int> da,db,dc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t,n,a,b,c,ans;
	cin>>t;
	for(int i=1;i<=t;i++){
		ans=0;
		da.clear();
		db.clear();
		dc.clear();
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a>>b>>c;
			if((a>b)&&(a>c)){
				da.push_back(a-max(b,c));
			}
			else if((b>a)&&(b>c)){
				db.push_back(b-max(a,c));
			}
			else{
				dc.push_back(c-max(a,b));
			}
			ans+=max(a,max(b,c));
		}
		if(da.size()>n/2){
			sort(da.begin(),da.end());
			for(int j=0;j<da.size()-n/2;j++){
				ans-=da[j];
			}
		}
		if(db.size()>n/2){
			sort(db.begin(),db.end());
			for(int j=0;j<db.size()-n/2;j++){
				ans-=db[j];
			}
		}
		if(dc.size()>n/2){
			sort(dc.begin(),dc.end());
			for(int j=0;j<dc.size()-n/2;j++){
				ans-=dc[j];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
