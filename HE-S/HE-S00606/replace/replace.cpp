#include<bits/stdc++.h>
using namespace std;

int n,q;
struct Node{
	string s1,s2;
};Node in[200010];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>in[i].s1>>in[i].s2;
	}
	
	string x1,x2;
	for(int i=1;i<=q;i++){
		cin>>x1>>x2;
		
		if(x1.size()!=x2.size()){
			cout<<0<<'\n';
			continue;
		}
		
		int sum=0;
		for(int j=1;j<=n;j++){
			string c,c1=x1,c2=x2;
			int xb=x1.find(in[j].s1);
			if(xb>5000000 || xb==-1)continue;
			c=c1.substr(0,xb)+in[j].s2+c2.substr(xb+in[j].s1.size(),c2.size()-(xb+in[j].s1.size()));
			if(c==x2){
				sum++;
			}
		}
		
		cout<<sum<<'\n';
		
	}
	
	return 0;
	
	fclose(stdin);
	fclose(stdout);
} 
