#include <bits/stdc++.h>
using namespace std;
int n,m=0;
int gun[5001];
bool f[5001];
void qa(int a,int b,int s){
	if(a>2*b){
		m++;
		m=m%998%244%353;
	}
	for(int i=s;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			qa(a+gun[i],gun[i],i);
			f[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>gun[i];
	sort(gun+1,gun+n+1);
	qa(0,0,1);
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 