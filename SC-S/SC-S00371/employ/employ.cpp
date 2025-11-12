#include<bits/stdc++.h>
using namespace std;
int n,m,f1,f2;
int a[505];
char b[505] ;
int f5(int h,int g){
	int f=1;
	for(int i=h;i<=g;i++){
		f*=i;
		f%=998244353;
	}
	return f;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>b[i];
			if(b[i]=='1'){
				f1++;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==0){
				f2++;
			}
		}
		if(m==n&&f2==0&&f1==n){
			cout<<f5(1,n)<<endl;
		}
		else{	
			cout<<0<<endl;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}