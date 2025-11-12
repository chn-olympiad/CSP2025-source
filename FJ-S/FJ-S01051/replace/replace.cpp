#include<bits/stdc++.h>
using namespace std;

int x[200005][2];
int y[200005][2];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int j=0;j<n;j++){
		string a,b;
		cin>>a>>b;
		for(int i=0;i<a.size();i++){
			if(a[i]=='b'){
				y[j][0]=i;
			}
			if(b[i]=='b'){
				y[j][1]=i;
			}
		}
		x[j][0]=y[j][1]-y[j][0];
		x[j][1]=a.size()-y[j][1];
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		int l,r;
		for(int i=0;i<a.size();i++){
			if(a[i]=='b'){
				l=i;
			}
			if(b[i]=='b'){
				r=i;
			}
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			if(x[i][0]==r-l&&l>=y[i][0]&&a.size()-r>=x[i][1]){
				cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
