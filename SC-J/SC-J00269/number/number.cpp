#include<bits/stdc++.h>
using namespace std;
string s;
int cnt=0;
int ans=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int cnt=0;
	int ans=0;
	for(int i=1;i<=s.size();i++){
		if(s[i]=='1' || '9' || '8' || '7'){
			cnt++;
		}
		if(s[i]=='2' || '3' || '4' || '5'){
			cnt++;
		}
		if(s[i]=='6'){
			cnt++;
		}
	}
	for(int i=1;i<=cnt;i++){
		for(int j=i+1;j<=cnt;j++){
			if(s[i]>=s[j]){
				for(int q=1;q<=cnt-1;q++)
					ans+=s[i]*10^(cnt-1);
			}
			else{
				for(int p=1;p<=cnt-1;p++)
					ans+=s[j]*10^(cnt-1);
			}
		}
		cnt--;
	}
	cout<<ans;
	return 0;
} 