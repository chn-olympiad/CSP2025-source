#include<bits/stdc++.h>
using namespace std;
int t,n,sum=0,op1=0,op2=0,op3=0;
struct node{
	int a;
	int b;
	int c;
};
node m[100007];
int cmpa(node x,node y){
	return x.a>y.a;
}
int cmpb(node x,node y){
	return x.b>y.b;
}
int cmpc(node x,node y){
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int ka=0,kb=0,kc=0;
	for(int kkk=1;kkk<=t;kkk++){
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
			ka=ka+m[i].a;
			kb=kb+m[i].b;
			kc=kc+m[i].c;
		}
		if(ka>=kb&&ka>=kc) sort(m+1,m+n+1,cmpa);
		else if(kb>=ka&&kb>=kc) sort(m+1,m+n+1,cmpb);
		else if(kc>=kb&&kc>=ka) sort(m+1,m+n+1,cmpc);
		for(int i=1;i<=n;i++){
			if(m[i].a>=m[i].b&&m[i].a>=m[i].c&&op1<n/2){
				op1++;
				sum=sum+m[i].a;
			}
			else{
				if(m[i].b>=m[i].a&&m[i].b>=m[i].c&&op2<n/2){
					op2++;
					sum=sum+m[i].b;
				}
				else{
					if(m[i].c>=m[i].b&&m[i].c>=m[i].a&&op3<n/2){
						op3++;
						sum=sum+m[i].c;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
