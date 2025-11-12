#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,q,ans;
string w,a,s[N][10];
string repla(int idx,string a,string b){
	for(int i=idx,j=0;i<idx+b.size();i++,j++)a[i]=b[j];
	return a;
}
string sub(int idx,int len,string a){
	string res="";
	for(int i=idx;i<idx+len;i++)res+=a[i];
	return a;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		cin>>s[i][1]>>s[i][2];
	while(q--){
		ans=0;
		cin>>w>>a;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=(int)w.size()-(int)s[i][1].size();j++){
//				cout<<s[i][1]<<' '<<w.substr(j,s[i][1].size())<<' '<<repla(j,w,s[i][2])<<' '<<j<<endl;
				if(w.substr(j,s[i][1].size())==s[i][1]&&repla(j,w,s[i][2])==a){
					ans++;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
