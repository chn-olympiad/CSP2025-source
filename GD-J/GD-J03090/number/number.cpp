#include<bits/stdc++.h>
#define let long long


#define rt return
using namespace std;

string s;
let n,mp[20],f;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	n = s.size();
	for(let i = 0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9') mp[int(s[i]-'0')]++;
	}
	for(let i =9;i>=0;i--){
		if(mp[i]>0){
			if(f == 0&&i == 0) cout<<0; 
			else for(let j = 1;j<=mp[i];j++,f++) cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	rt 0;
}
