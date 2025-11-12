#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;
map<string,string> mp;
int lens[5000005];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n ,q;
	string a,b,t1,t2;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> a >> b;
		mp[a] = b;
		lens[a.length()]++;
	}
//	for (auto &i:mp){
//		cout << i.first << " " << i.second << endl;
//	}
//	for (int i=1;i<=5;i++){
//		cout << lens[i] << " ";
//	}
	
	for (int i=1;i<=q;i++){
		int ans=0;
		cin >> t1 >> t2;
		for (int j=1;j<=t1.length();j++){
			if (lens[j]){
				for (int l=0;l+j-1<t1.length();l++){
//					cout << t1.substr(l,j)  << " " << l << " " << j<< endl;
					if (mp[t1.substr(l,j)]!=""){
//						cout << "OK" << endl;
//						cout << t1.substr(0,l)+mp[t1.substr(l,j)]+t1.substr(l+j);
						if (t1.substr(0,l)+mp[t1.substr(l,j)]+t1.substr(l+j)==t2){
							ans++;
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	
}