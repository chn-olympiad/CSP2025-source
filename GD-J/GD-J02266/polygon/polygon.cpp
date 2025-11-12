#include<bits/stdc++.h> 
using namespace std;
int a[5005],n;
int f(int x){
	int sum=1;
	for(int i=2;i<=x;i++)sum*=i;
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int num=0,k=f(n);
	for(int i=1;i<=n;i++){ 
		num=num+k/f(i)/f(n-i);
		//cout<<k<<" "<<f(i)<<" "<<f(n-i)<<" "<<k/f(i)/f(n-i)<<endl;
	}
	cout<<num;
	return 0;
}
/*
/*
            oo0880oo
           o88088888o
          o88   .  88o
         (88  _  _  88)
         U|    、    |U
		  |    _     |
		 _\_________/___
		/      V        \
	   /   __    ___|   |
	  |     |- (|       /
	  |_____|--\|______/ 
     ___|            |___
    /       _____       \
    \___________________/
   {======================}
   {[(佛祖保佑，代码全对)]} 
   {======================}

*/ 
*/
