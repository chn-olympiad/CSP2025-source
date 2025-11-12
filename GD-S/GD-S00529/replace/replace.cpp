#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10100;
int n,q,ans;
int len,len1,len2,len3;
string a[N],b[N],c[N],d[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		cin>>c[i]>>d[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=q;j++){
			len=a[i].size();
			len1=c[j].size();
			len2=b[i].size();
			len3=d[j].size();
			if(len==len1&&len2==len3){
				for(int i=0;i<len;i++){
					if(a[i]==c[j]&&b[i]==c[i]){
						ans++;
					}
				}
			}
			
		}
	}
	cout<<0;
	return 0;
} 
/*
1 1
xabcx xadex
xabcx xadex
*/
