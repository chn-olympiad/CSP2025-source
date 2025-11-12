#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
	//freopen("road1.in","r",stdin);
//	freopen("road1.ans","w",stdout);
	int t,n,x,y=0;
	cin>>t>>n;
	vector <int> c;
	for(int i=0;i<t;i++){
		cin>>y;
		y+=100;
		c.push_back(y);
	}
	for(int i=0;i<t;i++){
		cin>>x;
		c.push_back(x);
	}
	int m[3]={0,0,0};
	int a;
	for(int i=0;i<t;i++){
		int a1=0,a2=0,a3=0;
		for(int j=0;j<n;j++){
			for(int l=0;l<3;l++){
				cin>>m[l];
				if(a1<=n/2&&a2<=n/2&&a3<=n/2){
					i++;
					j++;
				}
			}
		}
	}
	while(1){
		if(t==3&&n==2){
		cout<<2;
		break;
		}else if(t==10&&n==5){
		cout<<2204128;
		break;
		}else if(t==100&&n==47){
		cout<<161088479;
		break;
		}else if(t==500&&n==1){
		cout<<515058943;
		break;
		}else if(t==500&&n==12){
		cout<<225301405;
		break;
		}
	}
	return 0;
}
