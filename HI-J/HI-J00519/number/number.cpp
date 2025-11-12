#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	long long k=0,sam=0;
	long long tmp=0,shuwei=1,out=0;
	cin>>a;
	int b[a.size()]={};
	for(int i=0;i<a.size();i++){
		if(int(a[i])<=57&&int(a[i])>=48){
//			cout<<int(a[i])<<" ";
			sam++;
			if(a[i]!=48){
				b[i]=a[i]-48;
				
			}
			else{
				b[i]=-1;
				shuwei*=10;
				
			}
		}
	}
	
	int c[sam]={};
	
	
	int j=0;
	for(int i=0;i<a.size();i++){
		
		if(b[i]!=0){
			c[j]=b[i];
			j++;
		}
	}
	
	sort(c,c+sam,greater<int>());
	
	for(int i=0;i<sam;i++){
		if(c[i]==-1)	c[i]=0;
//		if(b[i]!=0&&shuwei==0){
//			shuwei=1;
//			
//		}
//		if(b[i]!=0){
//			shuwei=1;
			
//		}
//		if(b[i]==66){
//			shuwei*=10;
//		}
	}
	
	
//	for(int i=0;i<a.size();i++){
//		cout<<b[i]<<" ";
//	}
//

//	cout<<out;
	for(int i=0;i<sam;i++){
		cout<<c[i];
	}
	
	return 0;
}
