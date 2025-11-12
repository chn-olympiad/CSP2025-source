#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int A=27;
ll has[200010][3];
ll h1[5000010],h2[5000010];
int ha[5000010];
string x,q1,q2;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=2;j++){
			cin>>x;
			for (int k=0;k<x.size();k++){
				has[i][j]=has[i][j]*A+x[k]-'a';
			}
		}
		ha[i]=x.size();
	}
	for (int i=1;i<=q;i++){
		int ans=0;
		cin>>q1>>q2;
		q1=' '+q1;
		q2=' '+q2;
		for (int i=1;i<q1.size();i++){
			h1[i]=h1[i-1]*A+q1[i]-'a';
		}
		for (int i=1;i<q2.size();i++){
			h2[i]=h2[i-1]*A+q2[i]-'a';
		}
		for (int i=1;i<=n;i++){
			int l=ha[i];
			for (int j=1;j+l-1<q1.size();j++){
				if (h1[l+j-1]-h1[j-1]*pow(A,l-j)==has[i][1]&&h2[j+l-1]-h2[j-1]*pow(A,l-j)==has[i][2])	ans++;
			}
		}
		cout<<0<<endl;
	}
	return 0;
}
