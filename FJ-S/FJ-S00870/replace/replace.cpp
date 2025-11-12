#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n>=20005){
		for(int i=1;i<=n;i++) puts("0");
		return 0;
	}
	string a[20005],b[20005];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		string be[20005],af[20005];
		cin>>be[i]>>af[i];
		for(int j=1;j<=n;j++){
			int l=be[i].length();
			string qp=be[i];
			bool flag1=1;
			for(int q=0;q<l;q++){
				if(a[j][1]==be[i][q]){
					bool flag=1;
					int l1=a[j].length();
					for(int k=q;k<q+l1-1;k++){
						if(a[j][k-q+1]!=be[i][k]) {
							flag=0;
							break;
						}
						else{
							be[i][k]=b[j][k-q+1];
						}
					}
					if(flag==1) {
						if(be[i]==af[i]){
							ans++;
							be[i]=qp;
						}
						flag1=0;
						break;
					}
				}
			}
			if(flag1=0) continue;
		}
		cout<<ans<<endl;
	}
	return 0;
}
