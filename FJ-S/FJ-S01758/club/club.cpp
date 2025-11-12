#include <bits/stdc++.h> 
using namespace std;
int n,t;
int a[10005];
int b[10005];
int c[10005];
int comp(int x,int y,int z){
	if(x>y){
		if(x>z) return x;
		else return z;
	}else{
		if(y>z)return y;
		else return z;
	}
}
int main(){
	freopen("club.in","w",stdin);
	freopen("club.out","r",stdout);
	cin>>t;
    while(t--){
    	cin>>n;
    	int sum=0;
    	for(int i=0;i<n;i++){
    		cin>>a[i]>>b[i]>>c[i];
		} 
    	for(int i=0;i<n;i++){
    	    sum+=comp(a[i],b[i],c[i]);
		}
		cout<<sum<<endl;
	}
	return 0;
} 
