#include <bits/stdc++.h>
using namespace std;
map<string,string> m;
string a,b;
long long n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> a >> b;
		m[a]=b;
	}
	while(q--){
		string a,b;
		cin >> a >> b;
		if(a.size()!=b.size()){
			cout << 0;
			continue;
		}
		long long sum=0;
		for(int l=0;l<a.size();l++){
			string e="";
			for(int r=l;r<a.size();r++){
				e+=a[r];
				if(m.count(e)){
					string y=a;
					for(int i=l;i<=r;i++){
						y[i]=m[e][i-l];
					}
					if(y==b)sum++;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
