#include<bits/stdc++.h>
using namespace std;
int n,b[501],c[501],m;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	getline(cin,s);
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			b[i]=0;
		}else{
			b[i]=1;
		}
	}
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=0;i<n;i++){
		int x=1;
		for(int j=i+1;j<n;j++){
			if(c[i]>c[j]){
				x=0;
				swap(c[i],c[j]);
			}
		}
		if(x==1){
			break;
		}
	}
	int cnt=0,d=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
		if(b[j]==0){
			cnt++;
		}
		if(c[j]-cnt<=0){
			cnt=0;
			d=0;
			break;
		}
		d++;
		}
	}
	int d1=d;
		for(int i=d;i<n-1;i++){
			if(c[i]==c[i+1]){
				d=d+d1;
			}else{
				d1=d;
			}
		}
	if(d<m){
		printf("0\n");
	}else{
		
		printf("%d\n",d-m);
	}
	return 0;
} 
