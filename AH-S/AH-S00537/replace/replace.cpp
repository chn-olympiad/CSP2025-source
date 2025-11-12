#include<bits/stdc++.h>
using namespace std;
string a[5000010],b[5000010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=m;i++){
		string s2,s;
		int ans=0;
		cin>>s2>>s;
		for(int j=1;j<=n;j++){
			string s3=s2;
			int x=s3.find(a[j]);
		if(x!=-1){
			int lena=b[j].size();
			int lens=s3.size();
			for(int k=x,l=0;k<x+lena&&k<lens&&l<lena;k++,l++){
				s3[k]=b[j][l];
			}
			if(s3==s) ans++;
			//cout<<"hehe "<<x<<" "<<s3<<endl;
		}
		}
		cout<<ans<<endl;
	}
	return 0;
}
