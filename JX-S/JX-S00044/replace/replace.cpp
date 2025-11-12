#include<bits/stdc++.h>
#define ll long long
#define N 1000010
#define M 1010
using namespace std;
map<string ,string>o;
ll n,m,s;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		o[a]=b;
	}
	for(int i=1;i<=m;i++){
		s=0;
		string a,b,c,d,e,f;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<(int)a.size();i++){
			if(a[i]==b[i]){
				c+=a[i];
			}
			else{
				break;
			}
		}
		for(int i=a.size()-1;i>=0;i--){
			if(a[i]==b[i]){
				d+=a[i];
			}
			else{
				break;
			}
		}
	//	cout<<c<<" "<<d<<endl;
		if(c.size()<d.size()){
			for(int i=0;i<(int)d.size();i++){
				for(int j=0;j<(int)c.size();j++){
					string e=a.substr(i,a.size()-i-j);
					string f=b.substr(i,b.size()-i-j);
					if(o[e]==f){
						++s;
					}
				}
			}
		}
		else{
			for(int i=0;i<=(int)c.size();i++){
				for(int j=0;j<=(int)d.size();j++){
					string e=a.substr(i,a.size()-i-j);
					string f=b.substr(i,b.size()-i-j);
					//cout<<e<<" "<<f<<endl;
					if(o[e]==f){
						++s;
					}
				}
			}
		}
		cout<<s<<endl;
	}
	
    return 0;
}
