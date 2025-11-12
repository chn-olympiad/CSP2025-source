//GZ-S00406 六盘水市知见外国学校 覃圣超 
#include<bits/stdc++.h>
using namespace std;
int a[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("empioy.out","w",stdout);
	int n,m,b,x=0,s=1;
	cin>>n>>m>>b;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		x=0;
		for(int j=1;j<=n;j++)
		if(a[j]==i){
			x+=1;
		}
		s=s*x;
	}
	cout<<s;
	fclose(stdin); 
	fclose(stdout);
	return 0;
}
