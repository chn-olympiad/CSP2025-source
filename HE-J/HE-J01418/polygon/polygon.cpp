#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxx=-1;
	cin>>n;
	vector<int>a;
	a.push_back(0);
	int aa;
	for(int i=1;i<=n;i++){
		cin>>aa;
		a.push_back(aa);
		if(aa>maxx){
			maxx=aa;
		}
	}
	if(n==3){
		if((a[1]+a[2]+a[3])>2*maxx){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		if(maxx==1){
			int a1=1,a2=1,a3=1,ss=0;
			for(int y=3;y<=n-1;y++){
				for(int q=1;q<=n;q++){
					a1*=q;
				}
				for(int qq=1;qq<=(n-y);qq++){
					a2*=qq;
				}
				for(int qqq=1;qqq<=y;qqq++){
					a3*=qqq;
				}
				ss+=a1/(a2*a3);
				a1=1;
				a2=1;
				a3=1;
			}
			cout<<ss+1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
