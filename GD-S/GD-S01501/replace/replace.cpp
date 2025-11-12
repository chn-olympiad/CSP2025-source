#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e6+2;

int a,b;
string n[maxn];
map<string,string> s;


int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		
		string s1,s2;
		cin>>s1>>s2;
		s[s1]=s2;
		n[i]=s1;
		
		
	}
	while(b--){
		
		string s1,s2;
		cin>>s1>>s2;
		string old=s1;
		int sum=0;
		for(int i=1;i<=a;i++){
			
			s1=old;
			
			int j=s1.find(n[i]);
			
			if(j!=-1){
				 
				//cout<<j<<' '<<n[i].size()<<endl;
				string x=s1.substr(0,j);
				string y=s1.substr(j,n[i].size());
				s1.erase(0,j);
				string z=s1.substr(n[i].size(),s1.size());
				
				string op1=x+s[n[i]]+z;
				string op2=s[n[i]]+y+z;
				string op3=x+y+s[n[i]];
//				cout<<s2<<' '<<op1<<' '<<op2<<' '<<op3<<' '<<s[n[i]]<<endl;
				if(s2==op1 or s2==op2 or s2==op3) sum++;
				 
			}
			
		}
		cout<<sum<<endl;
		
	}
	
	
	return 0;
	
} 
/*

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex

*/
