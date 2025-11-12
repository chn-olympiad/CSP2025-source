#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);	
string s;
cin>>s;
long long sum=0;
for(int i=0;i<=1000000;i++){
	int u=47,l=-1;
	for(int j=0;j<=1000000;j++){
		if(int(s[j])>u and int(s[j])<58){
			u=int(s[j]);
			l=j;
			}
		}
		sum=sum*10+u;
		s[l]='a';
		}
    cout<<sum;
	return 0;
}
