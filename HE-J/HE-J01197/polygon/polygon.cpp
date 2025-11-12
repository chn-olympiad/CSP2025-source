#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005],c;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,c=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
    }
    for(int i=1;i<=n;i++){
    	for(int j=3;j<=n;j++){
    				sort(a+i,a+j+1);
    		if(a[i]+a[i+1]+a[j]>a[j]*2)
    		c++;
		}
	}
cout<<c+1;	
fclose(stdin);
fclose(stdout);
}//I love zyh
