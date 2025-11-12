#include<bits/stdc++.h>
using namespace std;
struct node{
	string a,b;
}s[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    int n,q;
    cin>> n >> q;
    for(int i = 1;i <= n;i++){
    	cin>> s[i].a >> s[i].b;
	}
	while(q--){
		string x,y;
		cin>> x >> y;
		if(x.size() != y.size()){
			cout<< "0\n";
		}
		int len = x.length(),ans = 0;
		for(int i = 1;i <= n;i++){
	    	string A = s[i].a,B = s[i].b;
	    	int lea = A.length();
			if(lea > len){
				continue;
			}
			for(int j = 0;j <= len-lea;j++){
				bool f = 1;
		    	string s = x;
				for(int k = 0;k < lea;k++){
					if(s[j+k] != A[k]){
						f = 0;
						break;
					}
					s[j+k] = B[k];
				}
				if(f && s == y){
					ans++;
					break;
				}
			}
		}
		cout<< ans << "\n";
	}
	return 0;
}
