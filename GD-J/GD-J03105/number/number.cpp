#include<bits/stdc++.h>
using namespace std;
#define ll long long
string str;
int n,a[15];
int solve(){
//	scanf("%s",str+1);
	cin>>str;
	n=str.size();
	for(int i=0;i<n;i++){
		if(str[i]>='0' && str[i]<='9')a[str[i]-'0']++;
	}
	bool t=0;
	for(int i=9;i>=0;i--){
		while(a[i]--){
			if(i!=0)t=1;
			printf("%d",i);
			if(i==0 && t==0)break;
		}
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	solve();
	
	return 0;
}
//#Shang4Shan3Ruo6Shui4
