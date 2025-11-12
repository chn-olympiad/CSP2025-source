#include<bits/stdc++.h>
using namespace std;
int n,q,sum;
string s[100005][5],a,b,c,cc,ccc;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		sum=0;int r=a.size()-1,l=0;
		for(int j=0;j<a.size();j++){
			for(int jj=a.size()-1;jj>=j;jj--){
			l=j;r=jj;
			c="";cc="";ccc="";
			for(int k=0;k<l;k++){
				c+=a[k];
			}
			for(int k=l;k<=r;k++){
				cc+=a[k];
			}
			for(int k=r+1;k<a.size();k++){
				ccc+=a[k];
			}
			for(int k=1;k<=n;k++){
				if(cc==s[k][1]){
					cc=s[k][2];
					break;
				}
			}
			if(c+cc+ccc==b){
				sum++;
			}
		}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
