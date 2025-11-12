 #include<bits/stdc++.h>
 using namespace std;
 bool f(char a,char b){
 	return a>b;
 }
 int main(){
 	freopen("number.in","r",stdin);
 	freopen("number.out","w",stdout);
 	string s;
 	char a[1000005]={};
 	int cnt=0;
 	cin>>s;
 	for(int i=0;i<s.size();i++){
 		if(s[i]-'0'<10&&s[i]-'0'>=0){
 			a[cnt]=s[i];
 			cnt++;
		 }
	 }
	 sort(a,a+cnt,f);
	 for(int i=0;i<cnt;i++){
	 	cout<<a[i];
	 }
	 return 0;
 }