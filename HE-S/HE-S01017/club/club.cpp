#include<bits/stdc++.h>
using namespace std;
struct aaa{
	int q,w;
}m[100001];
bool f(aaa x,aaa y){
	return x.q>y.q;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	int z[6]={};
	for(int k=1;k<=n;k++){
		int a;
		cin>>a;
		int s=0;
		int a1=0,b2=0,c3=0;
		for(int i=1;i<=a;i++){
			for(int j=1;j<=3;j++){
				cin>>m[j].q;
				m[j].w=j;
			}
			sort(m+1,m+4,f);
			
			if(m[1].w==1){
				a1++;
			}else if(m[1].w==2){
				b2++;
			}else{
				c3++;
			}
			s+=m[1].q;
		}
		z[k]=s;
	}
	for(int i=1;i<=n;i++){
		cout<<z[i]<<endl;
	}
	return 0;
}
