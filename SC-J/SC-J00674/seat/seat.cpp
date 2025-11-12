#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],p,w;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin); freopen("seat.out","w",stdout); 
    cin>>n>>m;
    for(int i=1;i<=n*m;++i) scanf("%d",&a[i]);
    p=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;++i) if(a[i]==p) w=i;
    if(w<=n) cout<<"1 "<<w;   
    else{
	     if(w%n==0){  //倍数处理 
	     	cout<<w/n<<" ";  //列数 
	     	if((w/n)%2==0) cout<<n+1-(w/n);//偶数列 
	     	else cout<<w%n;  //奇数列 
		 }
	     
    	 else{
    	 	cout<<w/n+1<<" ";
    	 if((w/n+1)%2==0) cout<<n+1-(w%n);//偶数列 
	     	else cout<<w%n;  //奇数列 
		 }
	}
	fclose(stdin); fclose(stdout);
	return 0;
}