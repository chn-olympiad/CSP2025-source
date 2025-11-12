#include<bits/stdc++.h>
using namespace std;

int n,k,a[1000000];
bool z[1000000];
int sum2(string x){
	int y=0;
	int num=0;
	for(int i=0;i<x.size();i++){
		num+=pow(2,y)*(x[i]-'0');
		y++;
	}
	return num;
}
int sum1(int x,int y){
	
	string a,b;
	if(x==0)a+='0';
	if(y==0)b+='0'; 
	while(x){
		a+=((x%2)+'0' );		
		x/=2;
	}
	while(y){
		b+=((y%2)+'0' );		
		y/=2;
	}
	

	for(int i=0,j=0;i<a.size()&&j<b.size();i++,j++){
		if(a[i]!=b[j]){
		
			if(a[i]=='0'){
			a[i]='1';
		   }		   
		else
		{
			a[i]='0';
		}
			if(b[i]=='0'){
			b[i]='1';
		   }		   
		else
		{
			b[i]='0';
		}
	}	
	}
	if(a.size()>=b.size()){
		return sum2(a);
	}
	else{
		return sum2(b);
	}
}


int sum(int l,int r){
	
	int num=a[l];
	
	for(int i=l+1;i<=r;i++){
		num=sum1(num,a[i]);
	}

	return num;
}

bool sum3(int l,int r){
	for(int i=l;i<=r;i++){
		if(z[i]){
			return false;
		}
	}
	return true;
}

int main()
{
	
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	
	int p=0;
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		 for(int r=l;r<=n;r++){
		 	
			 if(sum3(l,r))
			 {
			    if(sum(l,r)==k)
				{
					p++;
					for(int j=l;j<=r;j++){
						z[j]=true;
					}				
				}
		 		
			 }
		 }
	}


cout<<p;
	return 0;
	
} 
