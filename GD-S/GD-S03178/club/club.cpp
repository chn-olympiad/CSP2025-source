#include<bits/stdc++.h>
using namespace std;
int t,n;
long long a[100009],b[100009],c[100009],as,n1,n2,n3;
int main(){
	freopen("club.in ","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int t1=1;t1<=t;t1++){
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		memset(b,0,sizeof(b));
		cin>>n;
		as=0;
		n1=0,n2=0,n3=0;
		for(int i=1;i<=n;i++){
			int a1,a2,a3;
			cin>>a1>>a2>>a3;
			if(a1>=a2&&a1>=a3)
			{
				n1++;
				as+=a1;
				if(a2>=a3)
				{
					a[a1-a2]++;
				}
				else{
					a[a1-a3]++;
				}
			}
			else if(a2>=a1&&a2>=a3)
			{
				n2++;
				as+=a2;
				if(a1>=a3)
				{
					b[a2-a1]++;
				}
				else{
					b[a2-a3]++;
				}
			}
			else if(a3>=a2&&a3>=a1)
			{
				n3++;
				as+=a3;
				if(a2>=a1)
				{
					c[a3-a2]++;
				}
				else{
					c[a3-a1]++;
				}
			}
		}
		if(n1>n/2){
			for(int i=0;i<=20000;i++){
				if(a[i]>=n1-n/2)
				{
					as-=i*(n1-n/2);
					break;
				}
				else{
					as-=i*a[i];
				}
				n1-=a[i];
			}
		}
		else if(n2>n/2){
			for(int i=0;i<=20000;i++){
				if(b[i]>=n2-n/2)
				{
					as-=i*(n2-n/2);
					break;
				}
				else{
					as-=i*b[i];
				}
				n2-=b[i];
			}
		}
		else if(n3>n/2){
			for(int i=0;i<=20000;i++){
				if(c[i]>=n3-n/2)
				{
					as-=i*(n3-n/2);
					break;
				}
				else{
					as-=i*c[i];
				}
				n3-=c[i];
			}
		}
		cout<<as<<endl;
	}
	fclose(stdin);
	fclose(stdout);
} 
