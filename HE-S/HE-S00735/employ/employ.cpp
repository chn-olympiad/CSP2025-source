#include <bits/stdc++.h>
using namespace std;
int n,m,k,a,b,c,sum,ans,rp=1;
int ci[100005],p[100005];
string aa;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	sum=n;
	cin >> aa;
	for (int i=0;i<n;i++){
		cin >> p[i];
		if(p[i]==0){
			sum--;
		}
		if (aa[i]=='1')ci[i]=1;
		else ci[i]=0;
	}
	for (int i=m;i>0;i--){
		rp*=i;
	}
	cout << rp/2;
	return 0;
}
	
