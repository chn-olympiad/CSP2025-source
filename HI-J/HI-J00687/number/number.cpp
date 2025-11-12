#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],cd;
bool cmp(int x,int y){
	return x>=y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			int pd=s[i]-48;
			if(pd==0||pd==1||pd==2||pd==3||pd==4||pd==5||pd==6||pd==7||pd==8||pd==9){
				a[i]=pd;
				cd++;
			}
		}
	}
	sort(a,a+s.size(),cmp);
	if(s.size()==1) cout<<s;
	else {
		for(int i=0;i<cd;i++){
			cout<<a[i];
		}
	}
	return 0;
}
//48~57
//290es1q0
//s[i]==0||s[i]==1||s[i]==2||s[i]==3||s[i]==4||s[i]==5||s[i]==6||s[i]==7||s[i]==8||s[i]==9
