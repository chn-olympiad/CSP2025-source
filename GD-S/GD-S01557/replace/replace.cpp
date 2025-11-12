#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,q,len[N];
pair<string,string>a[N],ans;
int solve(string x,string y){
	int cnt=0;
	if(x.size()!=1){
		for(int i=0;i<x.size();i++){
			string xp=x;
			for(int j=1;j<=n;j++){
				if(xp.size()-i>=len[j]){
					string l=xp.substr(i,len[j]);
					string p=xp.substr(0,i),q;
					if(x.size()-(i+len[j]-1)>0){
						q=xp.substr(i+len[j],xp.size()-1-(i+len[j]-1));
					}
//					cout<<endl<<p<<" "<<l<<" "<<q<<endl;
					if(l==a[j].first){
						xp=p+a[j].second+q;
					}
					if(xp==y){
						cnt++;
						break;
					}
				}
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i].first==x&&a[i].second==y){
				return 1;
			}
		}
		return 0;
	}
	return cnt;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		len[i]=a[i].first.size();
	}
	for(int i=1;i<=q;i++){
		cin>>ans.first>>ans.second;
		cout<<solve(ans.first,ans.second)<<endl;
	}
	return 0;
}

