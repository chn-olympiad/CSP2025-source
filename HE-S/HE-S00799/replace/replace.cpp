#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[1000010][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		int c=0;
		string a,b;
		cin>>a>>b;
		for(int j=0;j<=a.size();j++){
			for(int k=j+1;k<=a.size();k++){
				string c1,c2,c3;
				for(int p=0;p<=j-1;p++){
					c1=c1+a[p];
				}
				for(int p=j;p<=k-1;p++){
					c2=c2+a[p];
				}
				for(int p=k;p<a.size();p++){
					c3=c3+a[p];
				}
				
				for(int p=1;p<=n;p++){
					if(c2==s[p][1]){
						c2=s[p][2];
						break;
					}
				}
				
				if(c1+c2+c3==b){
					c++;
				}
//				cout<<c1+c2+c3<<" "<<b<<endl;
			}
		}
		cout<<c<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
