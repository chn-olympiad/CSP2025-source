#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[400005];

bool inpart(string a,string b){
	int k=0;
	for(int i=0;i<=b.length();i++){
		if(a[k]==b[i]){
			if(k==a.length()) return k-a.length();
			k++;
		}else k=0;
	}
	return -1;
}

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i*2]>>s[i*2+1];
		//cout<<s[i*2]<<' '<<s[i*2+1]<<endl;
	}
	while(q--){
		int cnt=0;
		string a,b;
		cin>>a>>b;
		//cout<<a<<' '<<b<<' '<<q<<endl;
		for(int i=1;i<=n;i++){
			int t=inpart(s[i*2],a);
			if(t+1){
				string ts=a;
				for(int j=t;j<=s[i*2+1].length();j++){
					ts[j]=s[i*2+1][j];
				}
				ts.erase(t+s[i*2+1].length(),s[i*2].length()+t);
				if(ts==b) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
