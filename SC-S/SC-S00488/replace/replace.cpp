#include<bits/stdc++.h>
using namespace std;

struct node{
	string a,b;
}s[200009];

int n,q;
int wz[200009],xb;

void find(string a,string c){
	for(int i=0;i<c.size();i++){
		for(int j=0;j<=a.size();j++){
			if(j==a.size()){
				wz[++xb]=i;
				continue;
			}
			if(a[j]!=c[i+j]) break;
		}
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
	}
	for(int i=1;i<=q;i++){
		string c,d;
		int ans=0;
		cin>>c>>d;
		for(int j=1;j<=n;j++){
			xb=0;
			find(s[j].a,c);
			for(int k=1;k<=xb;k++){
				string t="",p=s[j].b;
				for(int l=0;l<c.size();l++){
					if(l>=wz[k]&&l<=wz[k]+p.size()-1) t+=p[l-wz[k]];
					else t+=c[l];
				}
				if(t==d) ans++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
