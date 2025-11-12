#include<bits/stdc++.h>
using namespace std;
int t,sm[20000];
string s;
int si(string x,int a,int b,int c){//stoi
	int o=0,g=0;
	for(int k=a;k>=b;k+=c){
		o+=int(x[k]-'0')*pow(10,g);
		g++;
	}return o;	
}struct NBS{
	int as,bs,cs;//a,b,c-smile
}nb[200000];
int main(){
	freopen("club.in","r",stdin);
	getline(cin,s);
	t=int(s[0]-'0');
	for(int i=0;i<t;i++){
		getline(cin,s);
		int n=si(s,s.length()-1,0,1);
		for(int j=0;j<n;j++){
			int g,k;
			g=0;
			getline(cin,s);
			for(k=s.length()-1;s[k]!=' ';k--){
				nb[j].cs+=int(s[k]-'0')*pow(10,g);
				g++;
			}g=0;k--;
			for(;s[k]!=' ';k--){
				nb[j].bs+=int(s[k]-'0')*pow(10,g);
				g++;
			}g=0;k--;
			for(;k>=0;k--){
				nb[j].as+=int(s[k]-'0')*pow(10,g);
				g++;
			}cout<<nb[j].as<<" "<<nb[j].bs<<" "<<nb[j].cs<<"\n";
		}
	}
	freopen("club.out","w",stdout);
	return 0;
}
