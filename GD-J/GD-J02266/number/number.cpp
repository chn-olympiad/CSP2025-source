#include<bits/stdc++.h> 
using namespace std;
string a;
int aa[1000005],n=-1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(int(a[i])<=57&&int(a[i])>=48){
			
			n++;
			aa[n]=int(a[i])-48;
			//cout<<int(a[i])-48<<" ";
			//cout<<aa[n];
		}
	}
	//cout<<endl;
	sort(aa,aa+n+1);
	if(aa[n-1]!=0){
		for(int i=n;i>=0;i--){
			cout<<aa[i];
		}
	}else cout<<0;
	return 0;
}/*
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
