#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[1009],b[1009],c,d;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		cin>>c>>d;
		int ans=0;
		int len1=c.length();
		int len2=d.length();
		if(len1!=len2){
			cout<<0<<"\n";
			continue ;
		}
		for(int j=len1;j>=1&&c[j]==d[j];j--){
			for(int i=1;i<=n;i++){
				bool flag=1;
				if(a[i].length()!=j)continue;
				for(int k=0;k<a[i].length();k++){
					if(a[i][k]!=c[k]||b[i][k]!=d[k]){
						flag=0;
						break;
					}
				}
				if(flag)ans++;
				//cout<<ans<<" ";
			}
		}
			
		for(int i=0;i<len1&&c[i]==d[i];i++){
			for(int j=len1;j>=0&&j-i-1<len1&&c[j]==d[j];j--){
				for(int k=1;k<=n;k++){
					
					if(a[k].length()!=j-i-1) continue;
					//if(i==1&&j==4)cout<<"***";
					bool flag=1;
					for(int l=0;l<a[k].length();l++){
						if(a[k][l]!=c[l+i+1]||b[k][l]!=d[l+i+1]){
							flag=0;
							break;
						}
					}
					if(flag)ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
