#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int len=t1.size();
		for(int i=1;i<=n;i++){
			int lena=a[i].size();
			for(int j=0;j<len-lena+1;j++){
				if(t1[j]==a[i][0]){
					string tmp=t1;
					bool f=0;
					for(int k=j;k<=j+lena-1;k++){
						if(tmp[k]!=a[i][k-j]){
							f=1;
							break;
						}
						else{
							tmp[k]=b[i][k-j];
						}
					}
					//cout<<tmp<<endl;
					if(f==0){
						if(tmp==t2) ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
