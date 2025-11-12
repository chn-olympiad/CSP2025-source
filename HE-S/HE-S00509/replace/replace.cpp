#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,q;
struct pairstr{
	string a;
	string b;
}p[200010];
bool canreplace(int id,string s,string x,string y,int num){
	for (int i=id;i<=s.size()+id-1;i++){
		x[i] = p[num].b[i-id];
	}
	if (x == y){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string x,y;
	cin >> n >> q;
	for (int i=1;i<=n;i++){
		cin >> p[i].a >> p[i].b;
	}
	while (q--){
		cin >> x >> y;
		ans=0;
		for (int i=1;i<=n;i++){
			int len=0;
			int id=0;
			string s="";
			for (int j=0;j<x.size();j++){
				if (x[j] == p[i].a[len]){
					s+=x[j];
					if (len==0){
						id=j;
					}
					len+=1;
					if (s == p[i].a){
						if (canreplace(id,s,x,y,i) == true){
							ans+=1;
						}
						continue; 
					}
				}else{
					len=0;
					s="";
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
