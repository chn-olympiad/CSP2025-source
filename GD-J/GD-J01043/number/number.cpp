#include<bits/stdc++.h>
using namespace std;
int vis[1000001];
bool j(int x,int y){
	return x>y;
}
int main(){	
	string s;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);  
	cin>>s;
	int countt=0;
	for(int i=0;i<=s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			vis[countt]=s[i]-'0';
			countt++;		
		}
	}
	sort(vis,vis+countt,j);
	for(int i=0;i<=countt-1;i++){
		cout<<vis[i];
	} 
	return 0;
}
