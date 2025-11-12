#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int su[s.size()],j=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			//cout<<1;
			su[j]=s[i]-'0';
			//cout<<su[j];
			j++;
			s[i]='a';
		}
	}
	int ma=0,m,ans=0;
	for(int i=0;i<j;i++){
		ma=0;
		for(int i=0;i<j;i++){
			if(su[i]==-1)continue;
			if(su[i]>ma){
				ma=su[i];
				m=i;
			}
		}
		su[m]=-1;
		cout<<ma;
	}
	return 0;
}
