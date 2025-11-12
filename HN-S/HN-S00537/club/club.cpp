#include<bits/stdc++.h>
using namespace std;
int n,num=0,sum=0;
struct lo{
	int a,b,c;
}x[100000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	while(n--){
		int ant[10000];
		int g=0;
		cin>>num;
		int u=num/2;
		for(int i=0;i<num;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
		}
		if(num<=2){
			sum=0;
			sum+=x[0].a;
			if(x[1].b>=x[1].c){
				sum+=x[1].b;
			}else{
				sum+=x[1].c;
			}
			ant[g++]=sum;
			sum=0;
			sum+=x[1].a;
			if(x[0].b>=x[0].c){
				sum+=x[0].b;
			}else{
				sum+=x[0].c;
			}
			ant[g++]=sum;
		}
		else{
			for(int i=0;i<num;i++){
				for(int j=i+1;j<num;j++){
					sum=0;
					if(j+u<=num){
						sum+=x[i].a;
						for(int l=0;l<u-1;l++){
							sum+=x[j+l].a;
						}
						for(int l=0;l<num;l++){
							if(l!=i and l!=j){
								if(x[l].b>=x[l].c){
									sum+=x[l].b;
								}else{
									sum+=x[l].c;
								}
							}
						}
					}else{
						break;
					}
					ant[g++]=sum;
				}
			}
		}
		int max=ant[0];
		for(int i=1;i<g;i++){
			if(max<ant[i]){
				max=ant[i];
			}
		}
		cout<<max<<endl;
	}
	return 0;
}
