#include<bits/stdc++.h>
using namespace std;
string a[20005],b[20005];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		string x,y;
		int sum=0;
		int l=0,r=0;
		cin>>x>>y;
		if(x.length()!=y.length()){
			cout<<0<<endl;
			continue;
		}
		for(int j=1;j<=x.length();j++){
			if(x[i]!=y[i]){
				l=i;
			}else if(!l&&x[i]==y[i]){
				r=i-1;
			}
		}
		for(int j=1;j<=n;j++){
			int len=0;
			for(int o=0;o<=r-l;o++){
				if(a[j][o]!=x[o+l])break; 
				len++;
			}
			if(len==a[j].size()){
				sum++;
			}
		}
	}
}
