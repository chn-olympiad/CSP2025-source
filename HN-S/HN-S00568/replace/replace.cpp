#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;cin>>a>>b;
		mp[a]=b;
		mp[b]=a;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		int ans=0;
		for(int i=0;i<a.size();i++){
			if(i-1>=0&&a[i-1]!=b[i-1])break;
			for(int j=a.size()-1;j>=0;j--){
				if(j+1<=a.size()-1&&a[j+1]!=b[j+1])break;
				string cnt1="",cnt2="";
				for(int k=i;k<=j;k++)cnt1=cnt1+a[k],cnt2=cnt2+b[k];
				if(mp[cnt1]==cnt2){
					//cout<<i<<' '<<j<<endl;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}


