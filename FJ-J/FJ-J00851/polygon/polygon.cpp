#include<bits\stdc++.h>
using namespace std;
int main(){
	freopen('polygon.in','r',stdin);
	freopen('polygon.out','w',stdout);
	int a,b[5000],c = 0,h,t;
	long long d = 0;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b[i];
	}
	sort(b,b+a);
	for(int i = 0;i<a;i++){
		h = i;
		t = h+2;
		c = b[h]+b[h+1];
		for(int j=h;t<=a;t++){
			c+=b[t];
			if(c>2*b[t]){
				d++;
			}
		}
	}
	cout<<d%998244353;
	fclose(stdin);
	fclose(stdout);	
	return 0;	
}
