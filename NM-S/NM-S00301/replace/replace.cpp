#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200010][3],t1,t2;
int main(){
	int i,j,c=0;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	while(q--){
		cin>>t1>>t2;
		c=0;
		if(t1.length()!=t2.length()){
			puts("0");
			continue;
		}
		for(i=0;i<(int)t1.length()-1;i++){
			for(j=1;j<(int)t1.length();j++){
				for(int l=1;l<=n;l++){
					if(t2==(t1.substr(0,i)+s[l][2]+t1.substr(j+1,t1.length()-j))&&t1.substr(i,j-i+1)==s[l][1])
						c++;
				}
			}
		}
		printf("%d\n",c);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
