#include <bits/stdc++.h>
using namespace std;
int shuzi[100100],ans=0,num=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			ans++;
			shuzi[i]=0;
			num++;
		}
		if(s[i]=='1'){
			ans++;
			shuzi[i]=1;
		}
		if(s[i]=='2'){
			ans++;
			shuzi[i]=2;
		}
		if(s[i]=='3'){
			ans++;
			shuzi[i]=3;
		}
		if(s[i]=='4'){
			ans++;
			shuzi[i]=4;
		}
		if(s[i]=='5'){
			ans++;
			shuzi[i]=5;
		}
		if(s[i]=='6'){
			ans++;
			shuzi[i]=6;
		}
		if(s[i]=='7'){
			ans++;
			shuzi[i]=7;
		}
		if(s[i]=='8'){
			ans++;
			shuzi[i]=8;
		}
		if(s[i]=='9'){
			ans++;
			shuzi[i]=9;
		}	
 }
 
	sort(shuzi,shuzi+ans+1);
	for(int i=100005;i>=0;i--){
		if(shuzi[i]!=0) cout<<shuzi[i];
	}
	for(int i=0;i<num;i++){
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
