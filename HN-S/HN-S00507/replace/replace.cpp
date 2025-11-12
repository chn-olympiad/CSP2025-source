#include<bits/stdc++.h>
using namespace std;
int n,q,d[200010];
string a[200010],b[200010],s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	//cout<<n<<q; 
	ios::sync_with_stdio(0);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		int m,n;
		//cout<<114514;
		for(int j=0;j<a[i].size();j++){
			if(a[i][j]=='b')m=j;
			if(b[i][j]=='b')n=j;
		}
		d[n-m]++;
	}
	for(int i=1;i<=q;i++){
		int x,y,c;
		cin>>s1>>s2;
		for(int j=0;j<s1.size();j++){
			if(s1[j]=='b')x=j;
			if(s2[j]=='b')y=j;
		}
		c=y-x;
		cout<<d[c]<<endl;
	}
	return 0;
}
