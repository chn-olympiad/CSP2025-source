//GZ-S00349遵义市第十九中学田钦瑞
#include<bits/stdc++.h>
using namespace std;
int f(int d,int b,int c){
	if(d>b&&d>c){
		return d;
	}else if(b>d&&b>>c){
		return b;
	}else if(c>d&&c>b){
		return c;
	}            
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m;
	cin>>n;
	int a[n+1][5];
	for(int i=1;i<=3;i++){
		cin>>m;
		int b[4]={0};
		for(int i=1;i<=m;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3]; 
		}
		for(int i=1;i<=m;i++){
			if(a[i][4]==a[1]){
				b[1]++;		
			}else if(a[i][4]==a[2]){
				b[2]++;
			}else{
				b[3]++;
			}
		}                                               
	}
	for(int i=1;i<=n;i++){
		cout<<b[i];
	}
	return 0;	
} 
