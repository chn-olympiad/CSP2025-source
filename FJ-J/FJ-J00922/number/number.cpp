#include<bits/stdc++.h>
using namespace std;
string s1;
bool bo1=false;
long long a=0,b=0,c=0,s[15]={},i,j;
int main(){
//	freopen("D:\\number4.in","r",stdin);

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);cout.tie(NULL);
	cin>>s1;
	a=s1.size();
	for(i=0;i<a;i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			s[s1[i]-'0']++;
		}
	}
	for(i=9;i>=1;i--){
		if(s[i]==0){
			continue;
		}
		bo1=true;
		for(j=1;j<=s[i];j++){
			cout<<i;
		}
	}
	if(bo1==true){
		if(s[0]!=0){
			for(i=1;i<=s[0];i++){
				cout<<'0';
			}
		}
	}
	else{
		cout<<'0';
	}
	cout<<endl;
	return 0;
}
