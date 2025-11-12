#include<bits/stdc++.h>
using namespace std;
string a[1000005],b[1000005];
int n,q,zjs=0;
int main(){
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		char as[100005],bs[100005];
		cin>>as>>bs;
		for(int j=0;;j++){
			if(as[j]==0){
				break;
			}
			if(as[j]!=bs[j]){
				a[i]+=as[j];
				b[i]+=bs[j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int cnt=0;
		string ar="",br="";
		string x,y;cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<0<<endl;
			continue;
		}
		for(int j=0;j<x.size();j++){
			if(x[j]!=y[j]){
				cnt++;
				ar+=x[j];
				br+=y[j];
			}
		}
		for(int j=1;j<=n;i++){
			if(a[j].size()==cnt){
				if(ar==a[j]||ar==b[j]){
					if(br==a[j]||br==b[j]){
						zjs++;
					}
				}
			}
		}
	}
	cout<<zjs;
	return 0; 
}
