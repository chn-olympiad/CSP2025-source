#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string a[200005][3];
string x,y;
int n,q;
int cnt=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cnt=0;
		for(int i=1;i<=n;i++){
			int f=x.find(a[i][1]);
			while(f!=-1){
				string s=x;
				s.erase(f,a[i][1].size());
				s.insert(f,a[i][2]);
				if(s==y) cnt++;
				f=x.find(a[i][1],f+1);
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
