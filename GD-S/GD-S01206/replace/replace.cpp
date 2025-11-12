#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200005],b[200005],x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	while(q--){
		cin>>x>>y;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(x.find(a[i])!=-1){
				string yy=b[i];
				if(y.find(yy)!=-1){
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}//0分不用说了,乱写的 
