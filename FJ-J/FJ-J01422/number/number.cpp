#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a=0;
	int num[1001];
	int i=0,b=0,s=0;
	for(int d=0;d<=1000;d++){
		cin>>a;
		if(a%1==a){
			i++;
			num[i]=a;
			
		}	
	} 
		
	for(int y=1;y<=i;y++){
	for(int j=1;j<=i;j++){
		if(num[j]>b){
		swap(num[j],b);
		}
				
	}
	s=(s*10)+(b*10);	
	}
	cout<<s;
	scanf("%d",&s);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
