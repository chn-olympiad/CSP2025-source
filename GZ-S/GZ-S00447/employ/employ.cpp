//GZ-S00447 贵阳市第二十一中学 郭灏轩 
#include<bits/stdc++.h>
using namespace std;
int p[100005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n;
	cin>>n>>m;
	string s;
	cin>>s;
	int n1=n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]==0) n1--;
	}
	if(n1<m){
		cout<<0;
		return 0;
	}
	else{
		int cen=1;
		for(int i=1;i<=n1;i++) cen*=i;
		cout<<cen;
	}
	return 0;
}
