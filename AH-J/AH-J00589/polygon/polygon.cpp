#include<bits/stdc++.h>
using namespace std;
int n,cnt;
/*
bool f(int x,int y){
    int maxn=0,sum=0;
    for(int i=x;i<=y;i++){
        maxn=max(a[i],maxn);
        sum+=a[i];
	}
	return sum>maxn*2;
}
*/
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
    int x,y,z;
    cin>>x>>y>>z;
    if(x+y+z>max(x,max(y,z))){
        cout<<1;
    }else{
        cout<<0;
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
