#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	string s;
	cin>>s;
	int c[505],a[505];
	for(int i=1;i<=n;i++)a[i]=i;
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	do{
//		for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//		cout<<endl;
		int fail=0,success=0;
		for(int i=1;i<=n;i++){
//			cout<<fail<<" "<<c[a[i]]<<endl;
			if(fail>=c[a[i]]){
				fail++;
				continue;
			}
			if(s[i-1]=='0')fail++;
			else if(s[i-1]=='1')success++;
		}
		if(success>=m)ans++;
		
//		cout<<fail<<" "<<success<<"\n";
	}while(next_permutation(a+1,a+n+1));
	cout<<ans<<"\n";
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

10 5
1111111111
6 0 4 2 1 2 5 4 3 3
*/
