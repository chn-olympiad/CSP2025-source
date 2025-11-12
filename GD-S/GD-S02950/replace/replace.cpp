#include<bits/stdc++.h>
using namespace std;

int n, q;
map<string, string> m; 
string keys[200005];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin>>n>>q;
	
	for (int i=0;i<n;i++) {
		string key, word;
		cin>>key>>word;	
		m[key] = word;
		keys[i]=key;
	}
	
	for (int i=0;i<q;i++) {
		string a, b;
		cin>>a>>b;
		if (a.length() != b.length()) {
			cout<<0<<endl;
			continue;
		}
		int c=0;
		for (int h=0;h<n;h++) {
			string key=keys[h], word=m[keys[h]];
			int l = key.length();
			if (a.length()<l) continue;
			for (int j=0;j<=a.length()-l;j++) {
				
				string s="";
				for (int g=j;g<j+l;g++) {
					s+=a[g];
				}
				
				if (s==key) {
					string temp=a;
					for (int k=j;k<j+l;k++) {
						temp[k] = word[k-j];
					}
					if (temp==b) c+=1;
				}
			}
		}
		cout<<c<<endl;
	}
	
	return 0;
}
