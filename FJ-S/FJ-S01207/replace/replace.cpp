#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,l[200001];
	string a[200001],b[200001];
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		l[i]=a[i].length();
	}
	for(int i=1;i<=q;i++){
		string c,d;
		cin>>c>>d;
		int len=c.length(),sum=0;
		for(int j=1;j<=n;j++){
			for(int k=0;k+l[j]<len;k++){
				if(c.substr(k,l[j])!=a[j]){
					continue;
				}
				sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
