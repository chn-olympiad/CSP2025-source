#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
struct node{
	string x,y;
};
int n,m;
int kmp[maxn];
string a,b;
node s[maxn];
bool pand(string n,string m,int id){
	int i=0;
	while(i<n.size()){
		if(n[i]!=m[id]) return false;
		i++,id++;
	}
	return true;
}
bool rep(string n,string n1,string m,int id){
	int i=0;
	while(i<n1.size()){
		n[id+i]=n1[i];
		i++;
	}
	if(n==m) return true;
	return false;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int cnt;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i].x>>s[i].y;
	while(m--){
		cin>>a>>b;
		cnt=0;
		for(int i=1;i<=n;i++){
			int lena=a.size(),lens=s[i].x.size();
			if(lena-lens>=0)
				for(int j=0;j<=lena-lens;j++){
					if(pand(s[i].x,a,j)){
						if(rep(a,s[i].y,b,j)) cnt++;
					}
				}				
		}
		cout<<cnt<<endl;		
	}
	return 0;
}
