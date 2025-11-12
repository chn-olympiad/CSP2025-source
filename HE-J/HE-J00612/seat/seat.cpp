#include<bits/stdc++.h>
using namespace std;
int a,b,c[1000],num=0,m[1000],sum=0,w=0,r=0,y=0,xiao=0,ming=0,j=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	num=a*b;
	sum=num;
	for(int i=1;i<=num;i++){
		cin>>c[i];
	}
	xiao=c[1];
	while(num--){
		int max=0;
		for(int i=1;i<=sum;i++){
			if(c[i]>max){
				max=c[i];
				y=i;
			}
		}if(max!=0){
			r++;
			c[y]=-1;
			m[r]=max;	
		}
    }  
    for(int i=1;i<=sum;i++){
    	if(m[i]==xiao){
    		ming=i;
		}
	}
	int lie=0,hang=0;
    if(ming%a==0){
    	lie=ming/a; 
	}else{
		lie=ming/a+1;
	}
	cout<<lie<<" ";
	if(ming%a==0){
	    j=ming/a;
		if(j%2==0){
			hang=a;
		}else{
			hang=j+1;
		}
	}else{
		j=ming/a;
		if(j%2!=0){
			hang=a;
		}else{
			hang=a-(j%4-1);
		}
	}
	cout<<hang;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
