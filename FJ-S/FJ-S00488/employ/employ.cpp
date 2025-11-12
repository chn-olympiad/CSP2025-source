#include <iostream>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int p[100];
	int n,m,s;
	cin>>n;
	cin>>m;
	cin>>s;
	int e=s;
	int w=1,b=0,y=0;
	for (int i=1;i<n;i++){
		w=w*10;
	}
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		s=s/w;
		w=w/10;
		s=s%10;
	    	if(s%10==1){
	    		y=y+1;
	    		
	    	}else{
	    		b=b+1;
			}
		s=e;
	}
	cout<<y;
	return 0;
}
