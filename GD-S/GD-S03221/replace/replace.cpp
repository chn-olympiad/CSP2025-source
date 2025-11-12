#include<bits/stdc++.h>
using namespace std;
int n,q,sum;
string a[10001],b[10001],s1,s2,s3,s4,x,z,l;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		cin>>s1>>s2;
		sum=0;	
		for(int i=1;i<=n;i++){
			x="";
			for(int j=0;j<s1.size()-a[i].size()+1;j++){
				z=s1.substr(j+a[i].size(),s1.size()-j-a[i].size());
				l=s1.substr(j,a[i].size());
				s4=x+b[i];
				s4+=z;
				if(s4==s2 && l==a[i]){
					sum++;
				}
				x+=s1[j];
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}

