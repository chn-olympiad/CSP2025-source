#include<bits/stdc++.h>
using namespace std;
string s;
int sz=0,zd=0,z,w=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s.size()==1&&(s[0]>='0'&&s[0]<='9')) cout<<s;
	else{
		for(int i=0;i<=s.size();i++){
			if(s[i]>='0'&&s[i]<='9'){
				z=s[i]-48;
				if(sz==0&&w==0){
					sz=z;
					zd=z;
					w++;
				}else if(z>zd){
					sz+=z*pow(10,w);
					zd=z;
					w++;
				}else if(z<zd){
					sz=sz*10+z;
					w++;
				}
			} 
		}
		cout<<sz;
	}
	return 0;
}
