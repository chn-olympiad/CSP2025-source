#include <bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	freopen("replane.in","r",stdin);
	freopen("replane.out","w",stdout);
	cin >>n >>q;
	map<string,string> m;
	for(int i=0;i<n;i++){
		string a,b;
		cin >>a >>b;
		m[a]=b, m[b]=a;
	}
	while(q--){
		int ans=0;
		string s;
		cin >>s;
		for(int i=0;i<n;i++){
			string o=" ";
			o+=s[i];
			for(int j=i+1;j<n;j++){
				if(m.find(o)!=m.end()) ans++;
			    o+=s[j];    
		    }
		}
		cout <<ans <<"\n";
	}
	
}
