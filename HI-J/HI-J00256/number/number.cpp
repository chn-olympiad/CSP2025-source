#include<bits/stdc++.h>
freopen("number.in",".in",stdin);
freopen("out.txt","number .out",stdout);
using namespace std;
char s[1000000];
int main(){
	int a[1000000],cnt=0,Smal=1e5+5; 
	for(int i=0;i<1000000;i++){
		cin>>s[i];
		for(int j=0;j<i;j++){
		if(s[i]>=0&&s[i]<=9){
			a[j]=s[i];
			if(a[j]<=Smal)Smal=a[j];
		  }
		}
		if(i==0)cnt+=Smal;
		cnt+=Smal*10;	
		for(int j=0;j<i;j++){
		if(s[i]>0&&s[i]<=9){
			a[j]=s[i];
			if(a[j]==Smal)a[j]=1e5;
		  }
		}
	}
	cout<<cnt;
	return 0;
}
