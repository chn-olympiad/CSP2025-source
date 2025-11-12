#include<bits/stdc++.h>
using namespace std;
	int ygg(int x,int y,int z){
	if(x+y>z) return 1;
	else return 0;
}
int a[5010],b[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	//1~3 
	cout<<ygg(a[1],a[2],a[3])<<endl;
	//Ã¶¾Ù
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			b[j]=j;
		}
		while(1){
			for(if)
		}
	}*/
	return 0;
}
