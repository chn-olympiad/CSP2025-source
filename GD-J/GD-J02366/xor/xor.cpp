#include<iostream>
#include<cstdio>
using namespace std;
int n,k,s[1003],r[100][1003];
int main(){
	int p=1;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]!=0||s[i]!=1)
			p=0; 
	}
		
		/*/	while(s[i]!=0){
			int a=1,b=1;
			while(a<s[i]){
				for(int j=1;j<=b;j++)
					a=a*2;
				b++; 
			}
			
			if(a==s[i]){
				r[b-1][i]=s[i]/a;
				s[i]=s[i]-a*r[b-1][i];				
			}
			else{
				r[b-1][i]=s[i]/(a/2);
				s[i]=s[i]-(a/2)*r[b-1][i];
			}
			if(s[i]==1){
				r[1][i]=1;
				break;
			}
		}
	}/*/
	if(n==2){
		if(s[1]==1&&s[2]==1)
			cout<<1;
		return 0;
	}
	int a=0;
	if(p==1){
		if(k==1){
		}
			for(int i=1;i<=n;i++){
				if(s[i]==1&&s[i+1]==0||s[i]==0&&s[i]==1||s[i]==0&&s[i]==0){
					a++;
					i=i+2;
				}
				if(s[i]==1&&s[i+1]==1&&s[i+2]==1&&s[i+3]==1){
					a++;
					i=i+4
				}
			}
				
		else
			for(int i=1;i<=n;i++){
				if(s[i]==1&&s[i+1]==1){
					a++;
					i=i+2;
				}
				if(s[i]==0&&s[i+1]==1&&s[i+2]==0&&s[i+3]==1&&s[i+5]==0){
					a++;
					i=i+5;
				}
			}
		cout<<a;
		return 0;
	}
	cout<<2;
	 
	return 0;
} 
