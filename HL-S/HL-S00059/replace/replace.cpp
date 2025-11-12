#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string a[N][5],b[N][5];
int main(){
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>b[i][1]>>b[i][2];
		for(int j=0;j<(int)b[i][1].size();j++){
			if(b[i][1][j]!=b[i][2][j]){
				b[i][3]+=b[i][1][j];
				b[i][4]+=b[i][2][j];
			}
		}
//		cout<<b[i][3]<<" "<<b[i][4]<<endl;
	}
	for(int k=1;k<=q;k++){
	int ans=0;	
	for(int i=1;i<=n;i++){
		bool flag=1;
		if(a[i][1].find(b[k][3])==a[i][2].find(b[k][4])&&a[i][1].find(b[k][3])<=(int)b[k][3].size()&&a[i][1].find(b[k][3])>=0){
			for(int j=0;j<(int)a[i][1].size();j++){
				if(j==a[i][1].find(b[k][3])){
					j=a[i][1].find(b[k][3])+b[k][3].size()-1;
				}else{
					if(a[i][1][j]!=a[i][2][j]){
						flag=0;
						break;
					}
				}
			}
			if(flag==1){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	}
	return 0;
}
/*

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/

