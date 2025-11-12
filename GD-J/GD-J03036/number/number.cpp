#include <bits/stdc++.h>
using namespace std;  
 int num[10];
 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
   char a[1000005];
   cin>>a;
   for(int i=0;i<10;i++){
 	num[i]=0;
 }
	for(int i=0;i<1000005;i++){
		if(a[i]>='0'&&a[i]<='9'){
			num[a[i]-'0']+=1;
		}
		else{
			if(a[i]<=32){
				break;
			}
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++){
		cout<<i;
		} 
	}
	cout<<endl;
   return 0;
}
