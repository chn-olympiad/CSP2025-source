#include<bits/stdc++.h>
using namespace std;
int n,a[5005],v=0,b[5005],c[5005];
void check(int s,int ss){
	for(int i=0;i<n;i++){
		b[s]=i;
		if(s==0){
		int max=0,z=0;
		bool f=1;
			for(int j=0;j<ss+1;j++){
			if(max<a[b[j]])max=a[b[j]];
			z+=a[b[j]];
			}
			for(int j=0;j<ss;j++){
				for(int d=j+1;d<ss+1;d++){
				if(b[j]==b[d]||b[j]<b[d])f=0;
				}
			}
		if(z>max*2&&f==1){
			v++;
		}
		}else{
			check(s-1,ss);
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=2;i<n;i++){
		check(i,i);
	}
	cout<<v;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
