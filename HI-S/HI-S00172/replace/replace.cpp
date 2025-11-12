#include<bits/stdc++.h>
using namespace std;
map<string,string>k;
string l="2";
int main(){
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
   int n,q;
   cin>>n>>q;
   for(int i=1;i<=n;i++){
    string a,b;
    cin>>a>>b;
    k[a]=b;
   }
   while(q--){
    string a,b;
    int num=0;
    cin>>a>>b;
    if(a.size()!=b.size()){cout<<0<<"\n"; continue;}
    for(auto i:k){
    string x=i.first;
    string y=i.second;
	for(int j=0;j+x.size()-1<a.size();j++){
		if(a.substr(j,x.size())==x&&b.substr(j,y.size())==y){
			 string x1=a.substr(0,j),x2=a.substr(j+x.size(),a.size()-j-x.size());
			 if(x1+y+x2==b) {num++;
			// cout<<j<<" "<<y<<"\n";}
			}
		}
    }}
    cout<<num<<"\n";
   }
   fclose(stdin);
   fclose(stdout);
   return 0;
}
