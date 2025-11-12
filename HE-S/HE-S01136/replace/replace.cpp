#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int cnt=0;
	vector<string> a(n+1);
	vector<string> b(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	vector<string> s1(q+1),s2(q+1);
	for(int i=1;i<=q;i++){
		cin>>s1[i]>>s2[i];
		for(int d=1;d<=n;d++){
			int len1=a[d].length();
			for(int k=0;k<s1[i].length();k++){
				string dzd="";
				for(int j=0;j<=len1;j++){
					dzd+=s1[k+j];
			}
				if(dzd==a[i]) cnt++;
		} 
	}
	cout<<cnt<<endl;
}
	return 0;
}

