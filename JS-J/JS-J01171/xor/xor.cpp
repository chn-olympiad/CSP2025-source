#include<bits/stdc++.h>
using namespace std;
int n,k,maxx=-1;
long long a[500010];
vector<int> s[500010];//s[i][j]cong i dao j de quan zhi
int findd(int x,int y){
	for(int i=x;i<=n;i++){
		for(int j=y;j<=n;j++){
			
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i][i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			s[i][j]=s[i-1][j]^s[i][j-1];
		}
	}
	maxx=findd(1,1);
	return 0;
}
