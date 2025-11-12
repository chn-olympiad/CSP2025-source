#include<bits/stdc++.h> 
using namespace std;
string str;
int g[1000005],num=0;
bool cmd(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	int n=str.size();
	for(int i=0;i<n;i++){
		if(str[i]>='0'&&str[i]<='9'){
			num++;
			g[num]=str[i]-'0';
		}
	}
	sort(g+1,g+num+1,cmd);
	for(int i=1;i<=num;i++){
		cout<<g[i];
	}
	return 0;
}
