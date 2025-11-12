#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cd,i=0;
	string jg,s,cs,djg;
	cin>>s;
	cd=s.length();
	for(i=0;i<=cd;i++){
		cs[i]=s[i];
		if(cs[i]<='9'&&cs[i]>='0'){                                                                                         
			djg[i]='9'-('9'-cs[i]);
			jg +=djg[i];
			}    
		}
	cout<<jg;
	return 0;
}
