#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("input.in","r",stdin);
	//freopen("output.out","w",stdout);
	int n,o,i,j,b,t,c,f,g=0;
	int a[2];
	int d[2];
	for(o=0;o<3;o++){
		d[o]=0;
	}
	cin>>t;
	for(c=1;c<=t;c++){
		cin>>n;
		for(f=1;f<=n;f++){
			cin>>a[0]>>a[1]>>a[2];
			if(a[0]>=a[1]&&a[0]>=a[2]){
				d[0]=d[0]+1;
				g=g+a[0];
			}
			if(a[1]>=a[0]&&a[1]>=a[2]){
				d[1]=d[1]+1;
				g=g+a[1];
			}
			if(a[2]>=a[1]&&a[2]>=a[0]){
				d[2]=d[2]+1;
				g=g+a[2];
			}
	 }
	 if(d[0]>n/2||d[1]>n/2||d[2]>n/2){
				j=g-n/2;
				cout<<j<<endl;
				g=0;
			}
	 else{
	 	cout<<g<<endl;
	 	g=0;
	 }
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
