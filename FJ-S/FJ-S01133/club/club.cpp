#include<bits/stdc++.h>
using namespace std;
int t,n,a1[100005],a2[100005],a3[100005];
int num,b,c,a;
int compare(int x,int y,int z){
	if(a>n/2){
		if(b>n/2||z>y){	
			num+=z;
			c++;				
		}else if(c>n/2||y>z){
			num+=y;
			b++;
		}
	}else if(b>n/2){
		if(c>n/2||x>z){
			num+=x;
			a++;
			}
	}else if(x>y){
		if(x>z){
		num+=x;
		a++;
		}else{
			num+=z;
			c++;
		}
	}else if(y>z){
		num+=y;
		b++;
	}else{
		num+=z;
		c++;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(a3,0,sizeof(a3));
		num=0,b=0,c=0,a=0;
		cin>>n;
			for(int j=1;j<=n;j++)
				cin>>a1[j]>>a2[j]>>a3[j];
		for(int j=1;j<=n;j++)
			compare(a1[j],a2[j],a3[j]);
		cout<<num<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
