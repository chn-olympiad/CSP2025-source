#include<bits/stdc++.h>
namespace zcy{
	using namespace std;
	pair<string,string>t[1000001];
	int a,b;
	
	int dfs(string x,string y){
		int sum=0;
		if(x==y)sum++;
		for(int i=1;i<=a;i++){
//			cout<<x.size()<<" "<<t[i].first.size()<<endl; 
			for(int j=0;j<(int)x.size()-(int)t[i].first.size()+1;j++){
//				cout<<j<<endl;
				bool same=1;
//				cout<<x<<":"<<x[j]<<","<<t[i].first<<"->"<<t[i].second<<endl;
				for(int k=0;k<t[i].first.size();k++){
					if(t[i].first[k]!=x[j+k]){
						same=0;
//						cout<<
						break;
					}
				}
				if(same){
					string nw=x;
					for(int k=0;k<t[i].first.size();k++){
						nw[j+k]=t[i].second[k];
					}
					if(nw==y)sum++;
				}
			}
		}
		return sum;
	}
	
	int main(){
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
		cin>>a>>b;
//		cout<<a<<" "<<b<<endl;
		for(int i=1;i<=a;i++)cin>>t[i].first>>t[i].second;
		while(b--){
//			cout<<b<<endl;
			string x,y;
			cin>>x>>y;
			cout<<dfs(x,y)<<endl;
		}
		return 0;
	}
}
int main(){
	zcy::main();
	return 0;
}
