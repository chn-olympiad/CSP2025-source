#include<bits/stdc++.h>
using namespace std;
int main{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,num;
	cin>>n>>m;
	int s[n],c[m];
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int j=0;j<=m;j++){
		cin>>c[j];
	}
	for(int i=0;i<=n;i++){
		if(s[n]==0&&c[k]==1){
			continue;
		}
		else{
			num++;
		}
	}
	cout<<num<<endl;
	
	return 0;
}
