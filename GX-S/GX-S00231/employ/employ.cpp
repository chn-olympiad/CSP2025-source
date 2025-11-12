#include <bits/stdc++.h>
using namespace std;
int a[505],qwe=0;
string x;
int n,m;
void txt(int ren,int zao,int xun){
    if (zao>=m){
		qwe++;
		return;
	}
	for (int i=0;i<n;i++){
		if (a[i]>ren || xun==0){
			if (x[xun]=='1'){
				a[i]-=n+1;
				txt(ren,zao+1,xun+1);
				a[i]+=n+1;
			}
			else{
				a[i]-=n+1;
				txt(ren+1,zao,xun+1);
				a[i]+=n+1;
			}
		}
	}
	return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>x;
    for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	txt(0,0,0);
	cout<<qwe;
}
