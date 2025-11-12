#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],mp[11][11],c,r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}int fd=a[1],add=0,pd=1;
	sort(a+1,a+1+n*m,cmp);
	/*for(int i=1;i<=n*m;i++){
		add++;
		if(add>n){
			add=1;
			pd++;
		}
		if(a[i]==fd){
			if(pd%2==0){
				c=
			}
		}
	}*/
	for(int j=1;j<=m;j++){
		if(j%2!=0){
			for(int i=1;i<=n;i++){
				add++;
				mp[i][j]=a[add];
				//cout<<mp[i][j]<<" ";
			}
		}else{
			for(int i=n;i>0;i--){
				add++;
				mp[i][j]=a[add];
				//cout<<mp[i][j]<<" ";
			}
		}//cout<<endl;
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			//cout<<mp[i][j]<<" ";
			if(mp[i][j]==fd){
				cout<<j<<" "<<i;
				return 0;
			}
		}//cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 10
256 300 290 280 270 260 250 240 230 220
210 200 295 285 275 265 255 245 235 225
215 205 299 288 277 266 254 244 233 222

300 285 280 265 260 245 244 225 222 200
299 288 277 266 *256* "5 2" 240 230 220 205
295 290 275 270 255 254 235 233 215 210
*/
