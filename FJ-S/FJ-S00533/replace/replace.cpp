#include <bits/stdc++.h>
using namespace std;
struct st{
	string x;
	string y;
};
st h[200005];
int n,q,fs=0;
string a,b;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>h[i].x>>h[i].y;
	}
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		for(int j=1;j<=n;j++){
			int len=h[j].x.size();
			int len2=a.size();
		}
		cout<<fs<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
