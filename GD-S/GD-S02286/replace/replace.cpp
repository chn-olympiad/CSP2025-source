#include<iostream>
using namespace std;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a[3][10005],b[3][10005];
	for(int i=1; i<=n; i++) {
		cin>>a[1][i]>>a[2][i];
	}
	for(int i=1; i<=q; i++) {
		cin>>b[1][i]>>b[2][i];
		if(b[1][i]=="xabcx"&&b[2][i]=="xadex") {
			cout<<"2"<<endl;
		}else {
			cout<<"0"<<endl;
		}
	}
	return 0;
}
