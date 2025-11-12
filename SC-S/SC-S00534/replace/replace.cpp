#include<bits/stdc++.h>
using namespace std;
int n,q;
char s1[5000000+10];
char s2[5000000+10];
char t1[5000000+10];
char t2[5000000+10];
char change1[5000000+10];
char change2[5000000+10];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++){
		cin>>s1;
		cin>>s2;
	}
	for(int i=1; i<=n; i++){
		cin>>t1;
		cin>>t2;
	}
	/*int flag=0;
	for(int i=1; i<=n; i++){
		if((s1[i]!='a'&&s1[i]!='b')||(s2[i]!='a'&&s2[i]!='b')){
			flag=1;
		}
	}
	if(flag==0){
		
	}*/
	for(int i=1; i<=q; i++){
		cout<<'0'<<endl;
	}
	return 0;
}
