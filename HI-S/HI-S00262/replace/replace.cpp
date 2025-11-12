#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][3];
void hh(){
	int ans=0;
string ss1,ss2;
cin>>ss1>>ss2;
int len1=ss1.size();
int len2=ss2.size();
if(len1!=len2){
	cout<<0<<endl;
	return ;
}
for(int i=1;i<=n;i++){
int len=s[i][1].size();	
for(int j=0;j+len-1<len1;j++){
	bool f=1;
	for(int k=j,l=0;k<=j+len-1;k++,l++){
		if(ss1[k]!=s[i][1][l]){
			f=0;
			break;
			
		}
		
	}

	if(f==1){
		string  sx=ss1.substr(0,j);
		string sy=ss1.substr(j+len,len1);
		string sz=sx+s[i][2]+sy;

		if(sz==ss2){
			ans++;
		}else{
			break;
		}
	}
}
}
	cout<<ans<<endl;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}

	while(q--){
		hh();
	}
}
