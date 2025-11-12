 #include<bits/stdc++.h>
 using namespace std;
 struct node{
 	int id,cj,x,y;
 }a[1005];
 bool cmp(node a,node b){
 	return a.cj>b.cj;
 }
 int n,m;
 int ansx,ansy;
 int main(){
 	freopen("seat.in","r",stdin);
 	freopen("seat.out","w",stdout);
// 	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
 	
 	cin>>n>>m;
// 	if(n>=3||m>=3){
// 		solve();
//	 }
 	for(int i=1;i<=n*m;i++){
 		if(i==1){
 			a[1].id=1;
		 }
		 cin>>a[i].cj;
	 }
	 sort(a+1,a+1+n*m,cmp);
	 a[1].x=1;
	 a[1].y=1;
	 for(int i=2;i<=n*m;i++){
	 	if(a[i-1].y%2==0&&a[i-1].x-1>=1){
	 		
	 		a[i].y=a[i-1].y;
	 		if(a[i].y%2==1){
	 			a[i].x=a[i-1].x+1;
			 }else{
			 	a[i].x=a[i-1].x-1;
			 }}
		else if(a[i-1].y%2==1&&a[i-1].x+1<=n){
	 		
	 		a[i].y=a[i-1].y;
	 		if(a[i].y%2==1){
	 			a[i].x=a[i-1].x+1;
			 }else{
			 	a[i].x=a[i-1].x-1;
			 }
		 }else{
		 	
		 	a[i].y=a[i-1].y+1;
		 	if(a[i].y%2==1){
		 		a[i].x=1;
			 }else{
			 	a[i].x=n;
			 }
		 }
		 if(a[i].id==1){
		 	ansx=a[i].x;
		 	ansy=a[i].y;
		 	break;
		 }
	 }
	 cout<<ansy<<" "<<ansx;
 	return 0;
 }
 /*
 2 2
 98 99 100 97
 */
 
