#include<bits/stdc++.h>
using namespace std;
	pair<string,string>a[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;

	
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
	}
	sort(a,a+n);
	n=unique(a,a+n)-a;
	for(int i=0;i<q;i++){
		long long ans=0;
		string t1,t2;
		cin>>t1>>t2;
		
		
		for(int j=0;j<n;j++){
			int last=-1;	
			//cout<<last<<' '<<a[j].first<<endl;
			while((last=t1.find(a[j].first,last+1))!=-1){
			
				string t12=t1;
				t12.replace(last,a[j].first.size(),a[j].second);
				if(t12==t2){
					ans++;
				}	
				
			}
		}
		cout<<ans<<'\n';
	}
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	return 0;
}
