#include<bits/stdc++.h>
using namespace std;
string s;
long long vis[11];
int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			vis[int(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(vis[i]!=0){
			if(i!=0){
				for(int j=1;j<=vis[i];j++) cout<<i;
				n=1;
			}else if(i==0&&n==1){
				for(int j=1;j<=vis[i];j++) cout<<i;
			}else cout<<0;
		}
	}
	return 0;
}
