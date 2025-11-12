#include<bits/stdc++.h>
using namespace std;
int s[15][15];
int n,m,c,r;//小r座位第c列，第r行 
int a[105];
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i)cin>>a[i];	
	int ar=a[1],sr;//小r的成绩  小r的名次 
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;++i){
	 	if(a[i]==ar){
	 		sr=i; 
		 }
	 } 
	bool flag=0;//判断i是否出现过 
	for(int i=1;i<=m;++i){
	 	if(sr<=i*n&&flag==0){
	 		c=i;
	 		flag=1;
	 		if(i%2==0){ //为偶数列时
			   r=(i*n-sr)+1;
		    }
		    else {//为奇数列时 
		    	r=n-(i*n-sr); 
			}
	    }
	}
	cout<<c<<" "<<r<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}