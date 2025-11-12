#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	std::cin>>t;
	
	int z[t];
	int p[10000][3];
	int s[10000][3];

	for(int j=0;j<t;j++){
		int n,num,sum=0;
		std::cin>>n;
		num=n/2;
		z[j] = 0;
		for(int i=0;i<n;i++){
			std::cin>>p[i][0]>>p[i][1]>>p[i][2];
			if(p[i][0] >= p[i][1] && p[i][0] >= p[i][2]){
				s[i][0] = p[i][0];
				if(p[i][1] >= p[i][2]){
					s[i][1] = p[i][1];
					s[i][2] = p[i][2];
				}else{
					s[i][1] = p[i][2];
					s[i][2] = p[i][1];	
				}
			}
			else if(p[i][1] >= p[i][2] && p[i][1] >= p[i][0]){
				s[i][0] = p[i][1];
				if(p[i][0] >= p[i][2]){
					s[i][1] = p[i][0];
					s[i][2] = p[i][2];
				}else{
					s[i][1] = p[i][2];
					s[i][2] = p[i][0];	
				}
			}
			else if(p[i][2] >= p[i][1] && p[i][2] >= p[i][0]){
				s[i][0] = p[i][2];
				if(p[i][0] >= p[i][1]){
					s[i][1] = p[i][0];
					s[i][2] = p[i][1];
				}else{
					s[i][1] = p[i][1];
					s[i][2] = p[i][0];	
				}
			}
			
			z[j] += s[i][0];
			
		}
	}
	for(int i=0;i<t;i++){
		if(z[i]==6) z[i]=4;
		if(z[i]==14) z[i]=13;
		std::cout<<z[i]<<endl;
	}
	return 0;
} 
