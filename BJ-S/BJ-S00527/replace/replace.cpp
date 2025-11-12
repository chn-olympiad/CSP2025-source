#include <bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int nn,q;
struct node{
	string a,b;
}a[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>nn>>q;
	for(int i=1;i<=nn;i++){
		cin>>a[i].a>>a[i].b;
	}
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int n=t1.size();
		string c1,c2;
		for(int i=0;i<n;i++){
			if(i>0&&c1!=c2) continue;
			string h1,h2;
			for(int j=0;j<n;j++){
				if(j>0&&h1!=h2) continue;
				string qwq1;
				string qwq2;
				for(int k=i;k<n-j;k++){
					qwq1=qwq1+t1[k];
					qwq2=qwq2+t2[k];
				}
				for(int k=1;k<=nn;k++)
					if(a[k].a==qwq1&&a[k].b==qwq2) ans++;
				if(j==0) h1=t1[n-1],h2=t2[n-1];
				else h1=t1[n-i-1]+h1,h2=t2[n-i-1]+h2;
			}
			if(i==0) c1=t1[i],c2=t2[i];
			else c1=c1+t1[i],c2=c2+t2[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
