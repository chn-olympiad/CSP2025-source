 #include<bits/stdc++.h>
 using namespace std;
 string s;
// int a[1000005],ans;
vector<int>a;
string ans;
char c[1000005];
 int main(){
 	freopen("number.in","r",stdin);
 	freopen("number.out","w",stdout);
 	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
 	cin>>s;
 	int cnt=0;
 	for(int i=0;i<s.size();i++){
 		if(s[i]<='9'&&s[i]>='0'){
 			c[++cnt]=s[i];
		 }
	 }
	 
	 sort(c+1,c+1+cnt);
	 for(int i=cnt;i>=1;i--){
	 	ans=ans+c[i];
	 }
	 cout<<ans;
 	return 0;
 }
