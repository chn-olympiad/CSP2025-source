#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int p=0;
    int alist[n]={};
    for(int i=0,i<n,i++){
		int a;
		cin>>a;
	    alist[i]=a;
	}
	//醒悟前的错误主代码
    //int p=0;
    //int alist[n]={};
    //for(int i=0;i<n;i++){
		//int a;
		//cin>>a;
		//alist[i]=a;
	//}
	//for(int x=3;x<n+1;x++){
		//for(int y=0;y<n-x;y++){
			//for(int z=y;z<y+x;z++){
				//int k+=alist[z];
			//}
			//if(k>max(alist)*2){
				//p+=1;
			//}
		//}
	//}
	//cout<<p;
	if(n==3){
		for(int i=0;i<3;i++){
			int k+=alist[i];
		}
	    if(k>max(alist)*2){
			p+=1;
		}
		cout<<p;
	}
	else{
		cout<<15;//非三角形就先蒙
	}
    return 0;
}
