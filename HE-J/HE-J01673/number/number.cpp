#include<bits/stdc++.h>
using namespace std;
string s;
char a[10]={'0','1','2','3','4','5','6','7','8','9'};
int b[10]={0};	
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long int u=0,num=0,num2=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<10;j++){
			if(s[i]==a[j]){
				u++;
				b[j]++;
			}
		}
	}
	long long int c[u]={0};
	for(int i=0;i<=u+10000000;i++){
		if(b[9]>0){
			num2=num2+9;
			for(int j=1;j<u;j++){
				num2=num2*10;
			}
			b[9]--;
			u--;
			num=num+num2;
			num2=0;
		}else if(b[8]>0){
			num2=num2+8;
			for(int j=1;j<u;j++){
				num2=num2*10;
			}
			b[8]--;
			u--;
			num=num+num2;
			num2=0;
		}else if(b[7]>0){
			num2=num2+7;
			for(int j=1;j<u;j++){
				num2=num2*10;
			}
			b[7]--;
			u--;
			num=num+num2;
			num2=0;
		}else if(b[6]>0){
			num2=num2+6;
			for(int j=1;j<u;j++){
				num2=num2*10;
			}
			b[6]--;
			u--;
			num=num+num2;
			num2=0;
		}else if(b[5]>0){
			num2=num2+5;
			for(int j=1;j<u;j++){
				num2=num2*10;
			}
			b[5]--;
			u--;
			num=num+num2;
			num2=0;
		}else if(b[4]>0){
			num2=num2+4;
			for(int j=1;j<u;j++){
				num2=num2*10;
			}
			b[4]--;
			u--;
			num=num+num2;
			num2=0;
		}else if(b[3]>0){
			num2=num2+3;
			for(int j=1;j<u;j++){
				num2=num2*10;
			}
			b[3]--;
			u--;
			num=num+num2;
			num2=0;
		}else if(b[2]>0){
			num2=num2+2;
			for(int j=1;j<u;j++){
				num2=num2*10;
			}
			b[2]--;
			u--;
			num=num+num2;
			num2=0;
		}else if(b[1]>0){
			num2=num2+1;
			for(int j=1;j<u;j++){
				num2=num2*10;
			}
			b[1]--;
			u--;
			num=num+num2;
			num2=0;
		}else if(b[0]>0){
			for(int j=1;j<u;j++){
				num=num*10;
			}
			b[0]--;
			u--;
		}
	}
	cout<<num;
} 
