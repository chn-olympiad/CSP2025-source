#include<bits/stdc++.h>
using namespace std;
namespace jsk{
	int n,m;
	map<string,map<string,int> >arr;
	int main(){
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
		cin >> n >> m;
		for(int i=1;i<=n;i++){
			string a,b,c=" ",d=" ";
			cin >> a >> b;
			int l=-1,r;
			for(int j=0;j<a.size();j++){
				if(a[j]!=b[j]){
					r=j;
					if(l==-1){
						l=j;
					}
				}
			}
			for(int j=l;j<=r;j++){
				c+=a[j];
				d+=b[j];
			}
			arr[c][d]++;
		}
		for(int i=1;i<=m;i++){
			string a,b,c=" ",d=" ";
			cin >> a >> b;
			int l=-1,r;
			for(int j=0;j<a.size();j++){
				if(a[j]!=b[j]){
					r=j;
					if(l==-1){
						l=j;
					}
				}
			}
			for(int j=l;j<=r;j++){
				c+=a[j];
				d+=b[j];
			}
			cout << arr[c][d] << endl;
		}
		


		return 0;
	}
}
int main(){
	return jsk::main();
}

