//GZ-S00194 遵义航天高级中学 徐浩威 
#include <bits/stdc++.h>
using namespace std;
int n,q,ans=0;
string w[100005][5];
string a[100005][5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++)
		cin>>a[i][j];
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=2;j++)
			cin>>w[i][j];
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;j++)
			if(w[i][1]==a[j][1]&&w[i][2]==a[j][2]){
				ans++;
		}
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}

