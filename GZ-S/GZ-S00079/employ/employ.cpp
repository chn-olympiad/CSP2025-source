//GZ-S00079 贵阳市第三实验中学 向信昌
#include<bits/stdc++.h>
using namespace std;
int n=0,m=0,ans=1,cot=0;
int c[1001]; 
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.ans","w",stdout);
	cin>>n>>m>>s;
	cot=n;
	for(int i=0;i<n;i++) cin>>c[i];
	for(int i=m;i>=1;i--){
		ans*=cot;
		cot-=1;
	}
	cout<<ans;
	return 0;
}
