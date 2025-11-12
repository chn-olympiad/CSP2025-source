#include<bits/stdc++.h>
using namespace std;
long long da[15],ls1,ls2,ls3,ls0,n,t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=0;j<t;j++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>ls1>>ls2>>ls3;
			ls0=max(ls1,max(ls2,ls3));
			da[j]+=ls0;
		}
	}
	for(int i=0;i<t;i++){
		cout<<da[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
