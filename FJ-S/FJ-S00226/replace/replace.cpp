#include<bits/stdc++.h>
using namespace std;
int n,q;
struct z{
	string a,b;
}zfc[10000005];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>zfc[i].a>>zfc[i].b;
	}
	for (int i=1;i<=q;i++){
		int ans=0;
		string z1,z2;//z1=zabcx
		cin>>z1>>z2;
		for (int j=1;j<=n;j++){
			int idx=0;
			string z11=z1;
			if(z1.find(zfc[j].a)<50000005){
	//			cout<<zfc[j].a<<' '<<z1.find(zfc[j].a)<<' ';
				for (int l=z1.find(zfc[j].a);l<z1.find(zfc[j].a)+zfc[j].a.length();l++){
					z11[l]=zfc[j].b[idx++];
	//				cout<<z11<<endl;
				}
				if(z11==z2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//太好了出考场就有番外可以看,特地留到今天奖励一下自己，我是全世界最幸福的小女孩>V<
