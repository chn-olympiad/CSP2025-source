#include<bits/stdc++.h>
using namespace std;
string s={'0'},ss={'0'};
int k=1,n,m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=1;;i++){
		n++;
		if(s[i+1]=='0'){
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(s[i]>'z'&&s[i]<'a'){
			ss[k]=s[i];
			k++;
		}
	}
	for(int i=1;;i++){
		m++;
		if(ss[i+1]=='0'){
			break;
		}
	}
	for(int i=1;i<=m;i++){
		int h=0;
		for(int j=1;j<=m;j++){
			if(s[j]<s[j+1]){
				char t=s[j];
				s[j]=s[j+1];
				s[j+1]=t;
				h=1;
			}
		}
		if(h==0){
			break;
		}
	}
	cout<<ss;
	return 0;
}
