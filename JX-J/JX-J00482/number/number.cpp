#include<bits/stdc++.h>
using namespace std;
string s;
int vis[10];
bool f1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			vis[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(i==0){
			if(f1){
				for(int j=0;j<vis[i];j++){
					cout<<i;
				}		
			}else{
				if(vis[0])cout<<0;
				else break;
			}
		}else{
			for(int j=0;j<vis[i];j++){
				f1=1;
				cout<<i;
			}		
		}

	}
	return 0;
}
