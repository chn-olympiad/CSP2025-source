 #include<bits/stdc++.h>
 using namespace std;
 bool f(int a,int b){
 	return a>b;
 }
 int main(){
 	freopen("seat.in","r",stdin);
 	freopen("seat.out","w",stdout);
 	int m,n;
 	cin>>m>>n;
 	int a[1000]={};
 	for(int i=1;i<=m*n;i++){
 		cin>>a[i]; 
	 }
	 int find=a[1];
	 sort(a+1,a+n*m+1,f);
	 int x=1,y=1,cnt=1,xx=1;
	 while(a[cnt]!=find){
	 	if((x==m&&xx==1)||(x==1&&xx==-1)){
	 		y++;
	 		xx*=-1;
		 }
		 else x+=xx;
		 cnt++;
	 }
	 cout<<y<<' '<<x;
	 return 0;
 }