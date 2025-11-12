#include<bits/stdc++.h>
using namespace std;
const int mode=998244353;
bool cheak1(int x,int y,int z){
	int MAXN=max(x,max(y,z));
	return (x+y+z)>2*MAXN;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<=3){
		int a,b,c;
		cin>>a>>b>>c;
		int MAXN=max(a,max(c,b));
		if(a+b+c>MAXN)cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	int num[5007],aa[5007]={0};
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		aa[i]=aa[i-1]+num[i];
		sum+=num[i];
	}
	sort(num+1,num+1+n);
	if(sum<=1){
		cout<<0<<endl;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
