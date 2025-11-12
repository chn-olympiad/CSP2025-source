#include <iostream>
#include <cstring>
using namespace std;

int n,q;
char s[200007][2][1000],t1[1000],t2[1000];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			int x=-1;
			for(int k=1;k<=strlen(t1);k++){
				if(t1[k]==s[i][0][0]){
					x=k;
					break;
				}
			}
			if(x>=0){
				string tmp=t1;
				for(int j=x;s[i][0][j]!='\0';j++){
					tmp[j]=s[i][1][j];
				}
				if(tmp==t2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
