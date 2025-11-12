/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4 
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0*/


#include<bits/stdc++.h>
using namespace std;
long long n,t;
long long c3[505],c2[505],c1[505];
long long ans=0;
long long a3[255],a1[255],a2[255];
long long cmp=-100088;
long long p;
long long h1=0,h2=0,h3=0;
long long m1=1145145567,m2=1145145567,m3=1145145567;
long long w1,w2,w3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int o=0;o<t;o++){
		ans=0;
		cin>>n;
		p=n/2;
		for(int i=0;i<p;i++){
			a3[i]=0;
			a1[i]=0;
			a2[i]=0;
		}
		for(int i=0;i<n;i++){
			cmp=-1000000;
			cin>>c1[i]>>c2[i]>>c3[i];
			cmp=max(cmp,c1[i]);
			cmp=max(cmp,c2[i]);
			cmp=max(cmp,c3[i]);
				if(cmp=c1[i]){
			if(h1>=p){
				if(cmp>m1){
					a1[w1]=cmp;
				}
				sort(a1,a1+h1);
				w1=0;
				m1=a1[0];
			}
			else{
			a1[h1]=cmp;
			sort(a1,a1+h1);
			w1=0;
			m1=a1[0];
			h1++;	
			}
			
		}
		else if(cmp=c2[i]){
			
			if(h2>=p){
				if(cmp>m2){
					a2[w2]=cmp;
				}
				sort(a2,a2+p);
				w2=0;
				m2=a2[0];
			}
			else{
			a2[h2]=cmp;
			sort(a2,a2+h2);
			w2=0;
			m2=a2[0];
			h2++;	
			}
			
		}
		else if(cmp=c3[i]){
			
			if(h3>=p){
				if(cmp>m3){
					a3[w3]=cmp;
				}
				sort(a3,a3+p);
				w3=0;
				m3=a3[0];
			}
			
			else{
			a3[h3]=cmp;
			sort(a3,a3+h3);
			w3=0;
			m3=a3[0];
			h3++;	
			}
			
			
		} 	}
	for(int i=0;i<p;i++){
		ans=ans+a3[i]+a1[i]+a2[i];
	}
	
		cout<<ans;
	}
	
	
	
	
	return 0;
}





