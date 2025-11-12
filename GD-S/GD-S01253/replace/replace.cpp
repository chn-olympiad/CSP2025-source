#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdin);
	int m,n;
	string a[10005][2],b[10005][2];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i][1]>>b[i][2];
	}
	for(int i=1;i<=m;i++){
		int s=0;
		for(int j=1;j<=n;i++){
			if(a[j][1]==b[i][2]){
				s++;
			}
			if(a[j][1]==b[i][1]){
				s++;
			}
			if(a[j][2]==b[i][2]){
				s++;
			}
			if(a[j][2]==b[i][1]){ 
				s++;
			}
		}
		cout<<s;
	}
}
