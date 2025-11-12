#include<bits/stdc++.h>
using namespace std;
int n,n1,hao[4]={0},men1[1000000]={0},men2[1000000]={0},men3[1000000]={0};
int main(){
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		cin>>n;
	 	int a=0,b=0,c=0;
		for(int i=0;i<n;i++){
			int men1[1000000]={0},men2[1000000]={0},men3[1000000]={0};
			int a=0,b=0,c=0;
			cin>>n1;
			for(int j=0;j<n1;j++){
					cin>>hao[0]>>hao[1]>>hao[2];
					if(hao[0]>hao[1]){
						if(hao[0]>hao[2]){ 
							men1[a]=hao[0];
							a+=1; 
						}
						else{
							men3[c]=hao[2];
							c+=1;
						}
					}
					else
					{
						if(hao[1]>hao[2]){
							men2[b]=hao[1];
							b+=1;
						} 
						else{
							men3[c]=hao[2];
							c+=1;
						}
					}
				}		
				int a1=0,a11=0;
				if(a>n1/2){
					if(a<=0){
						break;
					} 
					for(int nu=0;nu<2;nu++){
						if(hao[1]>=hao[2]){
							men2[b]=hao[1];
							b+=1;
						}
						else{
							men3[c]=hao[2];
							c+=1;
						}
					}
				}
				int b1=0,b11=0; 
				if(b>n1/2){
					if(b<=0){
						break;
					} 
					men3[c]=hao[2];
					c+=1;
					b--;
				}
		int z=0;
			for(int nu=0;nu<a;nu++){
				z+=men1[nu];
			}
			for(int nu=0;nu<b;nu++){
				z+=men2[nu];
			}
			for(int nu=0;nu<c;nu++){
				z+=men3[nu];
			}
			cout<<z<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

