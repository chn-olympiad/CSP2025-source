#include<iostream>
#include<cmath> 
#include<cstdio> 
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int m,n,stu[105],R,sit,x,y,room[15][15],num;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
 	cin>>n>>m;
 	int len=n*m;
 	for(int i=1;i<=len;i++)
 	{
 		cin>>stu[i];
	}
	 R=stu[1];
	 sort(stu+1,stu+len+1,cmp);
	for(int i=1;i<=len;i++)
 	{
 		if(stu[i]==R){
 			sit=i;
 			break;
		 }
	}
	
	for(int i=1;i<=m;i++)
 	{
 		if(i%2!=0){
 			for(int j=1;j<=n;j++){
 			num++;
 			if(num==sit){
			 cout<<i<<" "<<j;
			 return 0;
			 }
		 }
		 }
		 else 
 		for(int j=n;j>=1;j--){
 			num++;
			if(num==sit){
			 cout<<i<<" "<<j;
			 return 0;
			 }	 
			 }
	}
	
	return 0;
}