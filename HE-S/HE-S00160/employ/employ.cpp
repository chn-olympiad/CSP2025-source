#include<bits/stdc++.h>
using namespace std;
int main(){
 	freopen("employ.in","r",stdin);
 	freopen("employ.out","W",stdout);
 	int n,m;//ren shu   xi wang ren shu
 	int x;//nai xing
 	char a[500];//ti mu nan du
 	int z[500];//xianbiao:naixing neirong:rengshu
 	int ans=0,aa=0;
	cin>>n>>m;
	cin>>a;
 	for(int i;i<=n;i++){
 		cin>>x;
 		z[x]++;
	 }
	for(int j;j<=n;j++){
 		if (a[j]=0){
 			aa++;
		 }
	}
	for(int y;y<=n;y++){
		if(z[y]!=0){
			ans+=z[y];
		}
	}
	ans-=aa;
	cout<<ans;
	return 0;
}
