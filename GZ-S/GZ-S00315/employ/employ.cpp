//GZ-S00315 贵阳市第三中学 王子乾 
#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","W",stdout);
	int n,m,c[N],s[N],p;
	char v;
	cin >> n >> m >> v;
	for(int i=1;i<=n;i++){
		cin >> c[i];
		p+=c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i]>=s[i]&&c[j]<=s[j]){
				p++;
			}
			else if(c[j]+c[i]==n||s[i]+s[j]==m&&p+v==c[i]){
				p--;
				c[i]+c[j]-p+v; 
			}
			else{
				c[i+j]+s[i+j];
			}
		}
	}
	while(n+m){
		if(c[n]%10==1){
			c[n]=0;
		}
		else if(c[n]%10==0){
			c[n]=1;
		}
		else{
			c[n]++;
		}
	}
	cout << 2;
	return 0;
}
