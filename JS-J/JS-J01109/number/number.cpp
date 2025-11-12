#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	char s[1000005];
	cin>>s;
	while(1){
    int ans=-1,x=-1;
	for(int i=0;i<100005;i++){
		if(s[i]>='0' and s[i]<='9'){
			if(ans<s[i]-'0'){
			ans=s[i]-'0';
			x=i;
			}
		}
	}
	if(ans==-1){
        return 0;
	}
	cout<<ans;
	s[x]='f';
}
	return 0;
}
