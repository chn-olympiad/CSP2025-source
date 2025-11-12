 #include<bits/stdc++.h>
 using namespace std;
 bool cop(int a,int b){
 	  return a>b;
 }
 int a[100];
 int main(){
 	freopen("seat.in","r",stdin);
 	freopen("seat.out","w",stdout);
 	int n,m;
 	cin>>n>>m;
 	int nn=n*m;
 	for(int i=1;i<=nn;i++){
 		cin>>a[i];
	 }
	 int cnt;
	 int r=a[1];
	 sort(a+1,a+nn+1,cop);
	 for(int i=1;i<=nn;i++){
	 	if(a[i]==r){
	 	   cnt=i;
		 }
	 }
	 int hang=cnt%n;
	 int lie=cnt/n+1;
	 if(cnt%n==0){
	 	hang=n;
	 	lie=cnt/n;
	 }
	 if(lie%2==1){
	    cout<<lie<<" "<<hang;	 
	 }else{
	 	cout<<lie<<" "<<n-hang+1;
	 }
	 fclose(stdin);
	 fclose(stdout);
 	return 0;
 }