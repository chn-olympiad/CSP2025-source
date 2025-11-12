#include<bits/stdc++.h>
using namespace std;
int a[11000][11000];
int s[11000];
int n,m,tot;
int main(){
	freopen("seat.cpp","r",stdin);
	freopen("seat.cpp","w",stdout);
	cin>>n;
	cin>>m;
	int k;
	tot=s[1];
		for(int i=1;i<=n*m;i++){     //输入 
			cin>>s[i];
		}
		for(int i=1;i<=n*m;i++){      //特殊性质A,B 
			int tot=0;
			int tott=0;
			if(s[i]==i)tot++;
			if(s[i]==n*m-i+1)tott++;
			if(tot==n*m||tott==n*m){
		
		}
		}	
		for(int i=1;i<=n;i++){      //排位 
			for(int j=1;j<=m;j++){
			a[j][i]=0;
				for(int k=1;k<=n*m;k++){
					if(s[k]>a[j][i]){
						a[j][i]=s[k];
					}                            
					for(int ii=1;ii<=n*m;ii++){      //找出最高分并将其变为0；
						if(s[ii]==a[j][i]){
							s[ii]=0;
						}
					} 
				}
			}
		}
		for(int i=1;i<=n;i++){     //搜索K 
			for(int j=1;j<=m;j++){
				if(a[j][i]==tot){
					cout<<j<<" "<<i;
				}
			}
		}
	return 0;
}
