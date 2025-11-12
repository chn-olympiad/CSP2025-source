#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long c[5],d,e=0,m[5];
	long long n=0;//单组最大 
	long long a,b;//a组数 b人数 
	cin>>a;

	
	for(long long x=1;x<=a;x++){//组数
	cin>>b;
	d=b/2;
	cout<<d<<endl;
	m[1]=0;
	m[2]=0;
	m[3]=0;
	////////////////////////////////////////
		for(long long y=1;y<=b;y++){//ren
			for(long long z=1;z<=3;z++){//3个位置 
				cin>>c[z];
			
				
	}
	n=max(c[1],max(c[2],c[3]));
	///////
	if(n==c[1]){
		
		if(m[1]>d&&m[2]<d&&m[3]<d){
			n=max(c[2],c[3]);
			if(n==c[2]){
				m[2]++;
			}else{
				m[3]++;
			}
		}else if(m[1]>d&&m[2]>d&&m[3]<d){
			n=m[3];
			m[3]++;
		}else if(m[1]>d&&m[2]<d&&m[3]>d){
			n=m[2];
			m[2]++;
		}else{
			m[1]++;
		}
	}
	//
	if(n==c[2]){
		if(m[2]>d&&m[1]<d&&m[3]<d){
			n=max(c[1],c[3]);
			if(n==c[1]){
				m[1]++;
			}else{
				m[3]++;
			}
		}else if(m[2]>d&&m[1]>d&&m[3]<d){
			n=m[3];
			m[3]++;
		}else if(m[2]>d&&m[1]<d&&m[3]>d){
			n=m[1];
			m[1]++;
		}else{
			m[2]++;
		}
	}
	//
	if(n==c[3]){
		if(m[3]>d&&m[1]<d&&m[2]<d){
			n=max(c[1],c[2]);
			if(n==c[1]){
				m[1]++;
			}else{
				m[2]++;
			}
		}else if(m[3]>d&&m[1]>d&&m[2]<d){
			n=m[2];
			m[2]++;
		}else if(m[3]>d&&m[1]<d&&m[2]>d){
			n=m[1];
			m[1]++;
		}else{
			m[3]++;
		}
	}
	////////
	e=e+n;
	n=0;
	}
	cout<<e<<endl;
	e=0;
	
	////////////////////////////////////////
	}

	return 0;
}
