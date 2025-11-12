#include <bits/stdc++.h>
using namespace std;
int n,m,a[10010],r,mapp[1009][1009],tot=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				mapp[j][i]=a[tot];
				tot++;
			}
		}
		else{
			for(int j=1;j<=n;j++){
				mapp[j][i]=a[tot];
				tot++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mapp[i][j]==r){
				cout<<j<<" "<<i<<"\n";
				return 0;
			}
		}
	}
    return 0;
}
//log
//9:03 yeah!! not greedy!
//just do it
//klongklangklongklang......
//thinking......
//9:08 joking? n,m<=10?
//9:11 i will code it
//9:17 code end
//9:18 CE
//9:19 not pass small cases
//Debuging......
//9:25 pass small cases
//9:28 not pass big cases
//9:33 pass big cases
//9:34 make homemade cases
//9:36 test homemade cases
//9:39 pass homemade csses
//What a simple T2!
//T2 end!!!!!!!!!!!!!!!!!!!!!
//check at 11:11 no problem
//what a lucky time!
