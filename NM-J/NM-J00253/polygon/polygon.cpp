#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int max;
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}sort(a,a+n,cmp);
	if(a[1]+a[2]>a[0])
	{
		cout<<1<<endl;
	}else{
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
