#include<bits/stdc++.h>
using namespace std;
int num[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	
	int u=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(s[i]=='1'){
				num[u]=1;
				u++;
			}
			else{
				num[u]=s[i]-'0';
				u++;
			}
		}
	}
	sort(num,num+u+1,cmp);
	for(int i=0;i<u;i++){
		cout<<num[i];
	}
	return 0;
}
