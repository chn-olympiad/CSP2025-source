#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	long long s[10];
	memset(s,0,sizeof(s));
	for(long long i=0;i<n.size();i++){
		if(n[i]<='9'&&n[i]>='0'){
			s[n[i]-'0']++;
		}
	}
	bool flag=true;
	for(long long i=9;i>=0;i--){
		if(flag==true&&i==0&&s[i]>0){
			cout<<0;
			exit(0);
		}
		else{
			while(s[i]--){
				cout<<i;
				flag=false;
			}
		}
	}
	return 0;
}
