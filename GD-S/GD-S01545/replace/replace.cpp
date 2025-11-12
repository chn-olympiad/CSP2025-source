#include <iostream>
#include <string>
using namespace std;
int n,q,len[200005];
string a[200005],b[200005],aa,bb;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i <= n;i++) cin>>a[i]>>b[i],len[i]=a[i].size();
	for(int i = 1;i <= q;i++){
		cin>>aa>>bb;
		int cnt=0;
		if(aa.size()==bb.size()) for(int j = 1;j <= n;j++){
			if(len[j]>aa.size()) continue;
			string aaa=aa;
			string t="";
			for(int k = 0;k < len[j];k++) t+=aa[k];
			int k;
			for(k = len[j];k < aa.size();k++){
				if(t==a[j]) break;
				t.erase(0,1);
				t+=aa[k];
			}
			if(t==a[j]){
				for(int l = k-len[j];l < k;l++) aaa[l]=b[j][l-k+len[j]];
//				cout<<aaa<<' '<<bb<<'\n';
				for(int l = 0;l < aaa.size();l++){
					if(aaa[l]!=bb[l]){
//						cout<<aaa<<'\n';
						cnt--;
						break;
					}
				}
				cnt++;
			}
//			else cout<<j;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
