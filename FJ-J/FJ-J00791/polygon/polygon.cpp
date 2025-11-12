#include<bits/stdc++.h> 
using namespace std;
bool shape(int a,b,c){
	int max=max({a,b,c})
	if(a+b+c>2*max)return true;
	else return false;
}
int main(){
	int n,s=0;
	long long sum;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n;
	int a[n],c[][3];
	for(int i=0;i,n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int z=0;z<n;z++)
			if(shape(a[i],a[j],a[z]))sum++;
			c[s][1]=i;
			c[s][2]=j;
			c[s][3]=z; 
			if(s>0){
				for(int p=s;p>=0;p--){
					for(int q=1;q<=3;q++)
					 
				 
			}
		}
	}
	cout<<sum;
	return 0;
}
