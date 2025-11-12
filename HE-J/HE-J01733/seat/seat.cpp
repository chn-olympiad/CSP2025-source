#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,cj,a,R,c;
	cin>>x>>y;
	cj=x*y;
	int cjsu[cj];
	
	for(int i=1;i<=cj;i++){
		cin>>cjsu[i];
	}
	R=cjsu[1];
	for(int i=1;i<=cj;i++){
		for(int j=1;j<=cj-1;j++){
			if(cjsu[j]<cjsu[j+1]){
				a=cjsu[j];
				cjsu[j]=cjsu[j+1];
				cjsu[j+1]=a;
			}
		}
	}
	int b=0;
	for(int i=1;i<=x;){
		for(int j=1;j<=cj;j++){
			b++;
			if(cjsu[b]==R){
				if(i>1){
					if(i%2==0){
						c=y-(j%y)+1;
					}
					else{
						c=j%y;
					}
				}
				else{
					c=j;
				}
				cout<<i<<" "<<c;
			}
			if(j%y==0&&(j-1)%y!=0){
				i++;	
			}
		}
	}
	return 0;
} 
