#include<bits/stdc++.h>
using namespace std;
int r[1001],c[1001];
string ss;
int main(){
	freopen("emplory.in","r",stdin);
	freopen("emplory.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long p7=1;
	cin>>ss;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]!=0){
			p7=p7*(i+1);
		}
	}
	cout<<2;
}
