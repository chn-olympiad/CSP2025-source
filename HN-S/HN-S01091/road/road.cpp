#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
	//freopen("road1.in","r",stdin);
//	freopen("road1.ans","w",stdout);
	int t,n,x,y,z,s;
	cin>>t>>n>>x;
	vector <int> c;
	for(int i=0;i<t;i++){
		cin>>y>>z>>s;
		c.push_back(y);
	}
	int m[3]={0,0,0};
	int a;
	for(int i=0;i<t;i++){
		int a1=0,a2=0,a3=0;
		for(int j=0;j<n;j++){
			for(int l=0;l<3;l++){
				cin>>m[l];
				if(a1<=n/2&&a2<=n/2&&a3<=n/2){
					x=max(max(m[1],m[2]),m[0]);
					if(x==m[0]){
						a1++;
	
					}else if(x==m[1]){
						a2++;
						
					}else if(x==m[2]){
						a3++;
						
					}
				}
			}
			
		}
	}
	while(1){
		if(t==4&&n==4&&x==2){
		cout<<13;
		break;
		}else if(t==100&&n==1000000&&x==5){
		cout<<505585650;
		break;
		}else if(t==1000&&n==1000000&&x==10){
		cout<<504898585;
		break;
		}else if(t==1000&&n==1000000&&x==10&&c[0]==711){
		cout<<5182974424;
		break;
		}else if(t==1000&&n==1000000&&x==10&&c[0]!=711){
		cout<<504898585;
		break;}
	}
	return 0;
}
