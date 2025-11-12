#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
char s1[2005][2005]={},s2[2005][2005]={};
char t1[2005],t2[2005],t3[2005]={};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int num=0,b=0,c=0,sum=0;
	int n,q,left1,left2;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<q;i++){
		cin>>t1>>t2;
		
		for(int u=0;u<n;u++){
			for(int u=0;u<strlen(t1);u++){
				t3[u]=t1[u];
			}
			
			c=1;
			for(int u=0;u<strlen(t1);u++){
				t3[u]=t1[u];
			}
			for(int j=0;j<strlen(t1)&&c==0;j++){
				if(t1[j]==s1[u][0]){
					left1=j;
					left2=0;
					while(t1[left1]==s1[u][left2]){
						num++;
						left1++;
						left2++;
						if(num==strlen(s1[u])){
							for(int l=j,k=0;j<strlen(s1[u]);l++,k++){
								t3[l]=s1[u][k];
							}
							c==1;
							for(int i=0;i<strlen(t2);i++){
								if(t3[i]!=t2[i]){
									b=1;
									continue;
								}
							}
							if(b==0){
								sum++;
							}
							b=0;
						}
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
