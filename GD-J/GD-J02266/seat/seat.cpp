#include<bits/stdc++.h> 
using namespace std;
int n,m,x;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		//cout<<a[i]<<" ";
	} //cout<<endl;
	x=a[0];
	sort(a,a+n*m);
	int j=1;
	for(int i=n*m-1;i>=0;i--){
		//cout<<a[i]<<" ";
		if(x==a[i]){
			x=j;
			break;
		}
		j++;
	} 
	//*
	//cout<<x%n<<" ";
	if(x%n==0){
		if((x/n)%2==0){
			cout<<x/n<<" "<<1;
		}else{
			cout<<x/n<<" "<<n;
		}
	}else{
		if((x/n+1)%2==0){
			cout<<x/n+1<<" "<<n-x%n+1;
		}else{
			cout<<x/n+1<<" "<<x%2;
		}
	}//*/
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
