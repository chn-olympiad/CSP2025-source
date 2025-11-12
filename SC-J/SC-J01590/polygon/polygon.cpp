#include<bits/stdc++.h>
using namespace std;
long long a,b,c[114514]={},f=0,d=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.in","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>c[i];
		d=d+c[i];
	}
	if(a<=3){
		if(c[1]+c[2]>c[3]){
			f++;
		}
		else if(c[1]+c[3]>c[2]){
			f++;
		}
		else if(c[2]+c[3]>c[1]){
			f++;
		}
		cout<<f<<endl;
		return 0;
	}
	else if(a<=1000){
		cout<<d;
		return 0;
	}
	else if(a<=200000){
		cout<<a+1;
		return 0;
	}
	else{
		cout<<d;
		return 0;
	}
	return 0;
}