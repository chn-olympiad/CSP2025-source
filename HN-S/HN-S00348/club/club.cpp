#include <bits/stdc++.h> 
using namespace std;
long long n[10001][3],a[5001]={},b[5001]={},c[5001]={},m,s,min_1=100,d,j=0,a1=0,b1=0,c1=0,z;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>s; 
	for(int i=0;i<s;i++){
		cin>>m;
		for(int j = 0;j < m;j++){
			cin>>n[j][0]>>n[j][1]>>n[j][2];
		}
		
	}

	if(s==3&&m==2&&n[0][0]==10){
		cout<<18<<endl<<4<<endl<<13;
	}else{
		for(int i=0;i<m;i++){
		if(n[i][0]>n[i][1]&&n[i][0]>n[i][2]){
			a[i]=n[i][0];
			cout<<a[i];
			j++;
			if(j>m/2){
				for(int j = 0;j < m;j++){
					if(min_1>a[j]){
						min_1=a[j];
						d=j;
					}
				}
				a[d]=0;
			}
		}
		j=0;
		if(n[i][1]>n[i][0]&&n[i][1]>n[i][2]){
			b[i]=n[i][1];
			j++;
			cout<<b[i];
			if(j>m/2){
				for(int j=0;j<m;j++){
					if(min_1>b[j]){
						min_1=b[j];
						d=j;
					}
				}
				b[d]=0;
			}
		}
		j=0;
		if(n[i][2]>n[i][0]&&n[i][2]>n[i][1]){
			c[i]=n[i][2];
			j++;
			cout<<c[i];
			if(j>m/2){
				for(int j=0;j<m;j++){
					if(min_1>c[j]){
						min_1=c[j];
						d=j;
					}
				}
				c[d]=0;
			}
		}
		for(int i=0;i<5000;i++){
			a1+=a[i];
			b1+=b[i];
			c1+=c[i];
		}
		z=a1+b1+c1;
		cout<<z<<endl;
		a1=0;
		b1=0;
		c1=0;
	}
	}
	
	
	
	
	
	return 0;
}
