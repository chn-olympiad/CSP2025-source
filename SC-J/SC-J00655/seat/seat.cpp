#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;
int a[110];
int main(){
	fre("seat");
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+1+n*m);
	int t=n*m,i=1,j=1,up=0;
	while(1){
		if(a[t]==x){
			cout<<j<<' '<<i;
			return 0;
		}
		t--;
		if(i==1&&up){
			up=0;
			j++;
			continue;
		}
		if(i==n&&!up){
			up=1;
			j++;
			continue;
		}
		if(up)i--;
		else i++;
	}
}
