#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s[200005][2],t[200005][2]; 
	int n,q,a[200005];
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=0;i<q;i++){
		cin>>t[i][0]>>t[i][1];
	}
	for(int i=0;i<q;i++){
		memset(a,0,sizeof(a));
		for(int j=0;j<sizeof(t[i][0]);j++){
			if(t[i][0]==t[i][1]){
				a[i]=1;
			}else{
				a[i]=0;
			}
		}
		for(int j=0;j<)
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
