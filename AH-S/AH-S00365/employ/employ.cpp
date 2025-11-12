#include<bits/stdc++.h>
using namespace std;
int n,m,c[10001];
bool flag=0;
string a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ,out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(m==n){
		int len=a.size();
		for(int i=0;i<len;i++){
			if(a[i]=='0'){
				flag=1;
			}
		}
		if(!flag){
			for(int i=1;i<=n;i++){
				if(c[i]==0){
					flag=1;
				}
			}
		}
		if(!flag)cout<<1;
		else cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
