#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("club.in","r",stdin);
	 freopen("club.out","w",stdout);
	int w,y,h,a,b,c;
	cin>>w;
	for(int i=0;i<=w;i++){
		int n;
		cin>>n;
		for(int j=0;j<=w;j++){
			cin>>a>>b>>c;
			if(a>b&&a>c){
				y+=a;
			}
			if(b>c&&b>a){
				y+=b;
			}
			if(c>b&&c>a){
				y+=c;
			}
		}
		cout<<y<<endl;
	}

	return 0;
	}
	

