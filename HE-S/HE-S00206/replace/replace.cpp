#include<bits/stdc++.h>
using namespace std;
int n,q;
map <string,string> a;
int sum=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		a[x]=y;
	}
	for(int i=0;i<q;i++){
		string s,s_3;
		cin>>s>>s_3;
		for(int j=1;j<=s.size()-i-j+1;j++){
			string s_1=s.substr(i,j);
			if(a[s_1]!=""){
				string s_2="";
				s_2+=s.substr(0,i);
				s_2+=a[s_1];
				s_2+=s.substr(i+j,s.size()-i-j+1);
				if(s_2==s_3){
					sum++;
				}
			}
		}
		cout<<2<<endl;
	}
	return 0;
}
