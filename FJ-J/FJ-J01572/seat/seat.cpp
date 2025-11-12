#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[100000];
int k,kk,kkk;//diyigeshu
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
		if(i==1)k=c[i];
	}
	sort(c+1,c+1+(n*m));
	for(int i=n*m;i>=1;i--){
		if(c[i]==k){
			kkk=i-1;
			break;
		}
	}
	if(m%2==1){
		int x=n,y=m;
		while(kkk--){
		if(y%2==1){
			if(x-1>=1&&x-1<=n)x--;
			else y--;
		}else{
			if(x+1<=n){
				x++;
			}else(x==n&&y!=m);y--;
		}
	}cout<<x<<" "<<y;
	}
	else{
		int x=1,y=m;
		kkk--;
		while(kkk--){
		if(y%2==1){
			if(x-1>=1&&x-1<=n)x--;
			else y--;
		}else{
			if(x+1<=n){
				x++;
			}else(x==n&&y!=m);y--;
		}
	}cout<<x<<" "<<y;
	}
	
	return 0;
}
