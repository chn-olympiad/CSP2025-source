#include<bits/stdc++.h>
using namespace std;
const int N=1e3,mod=998244353;
int n,m,summ=1;
string s;
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0){
			summ*=c[i];
		}
	}
	sort(c+1,c+1+n);
	cout<<summ<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
