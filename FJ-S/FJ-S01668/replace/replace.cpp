#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
struct node{
	string a,b;
}t[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> t[i].a >> t[i].b;
	}
	while(q--){
		string sx,sy;
		cin >> sx >> sy;
		long long ans=0;
		for(int i=1;i<=n;i++){
			int la=t[i].a.length(),lb=t[i].b.length(),lsx=sx.length();
			for(int j=0;j<lsx && (lsx-(j+la))>=0;j++){
				string tsxa=sx.substr(0,j),tsxb=sx.substr(j+la,lsx-(j+la-1)),tsxmid=sx.substr(j,la);
//				cout << "tsxa: "<< tsxa << "  tsxb: " << tsxb  << " tsxmid: " << tsxmid << "\n";
				if(tsxmid!=t[i].a)continue;
				string fin_sx=tsxa+t[i].b+tsxb;
				if(fin_sx==sy){
					ans++;
//					cout << "I AK IOI\n";
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
