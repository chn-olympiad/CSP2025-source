#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string c;
	int n[10];
	memset(n,0,sizeof(n));
	cin>>c;
	int len=c.size();
	for (int i=0;i<len;i++){
		if(c[i]>='0'&&c[i]<='9') n[c[i]-'0']++;
	}
	for (int i=9;i>=0;i--){
		for (int j=1;j<=n[i];j++) cout<<i;
	}
	return 0;
} 
