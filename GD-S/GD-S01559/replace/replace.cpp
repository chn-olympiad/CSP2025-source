#include <bits/stdc++.h>
using namespace std;
long long a,b,f=0;
struct aa{
	string a,b;
}c[200005];
bool cmp(aa d,aa e){
	return d.a>e.a;
}
string d,e;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>a>>b;
	for(int z=1;z<=a;z++){
		cin>>c[z].a>>c[z].b;
	}
	sort(c+1,c+1+a,cmp);
	while(b--){
		f=0;
		cin>>d>>e;
		string g="";
		for(int z=0;z<d.length();z++){
			for(int y=1;y<=a;y++){
				string h;
				for(int x=0;x<=d.length()-c[y].a.length();x++){
					h=g;
					h+=c[y].b;
					for(int w=x+c[y].b.length();w<a;w++){
						h+=d[z];
					}
				}
				if(h==e)f++;
			}
			g+=d[z];
		}
		cout<<f;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
