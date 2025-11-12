#include<bits/stdc++.h>
using namespace std;
char a[1000];
int b[1000],c[1000];
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	
	cin>>a;
	if(a[1]==0&&a[2]==0&&a[3]==0){
		cout<<a-48;
	}
	else{
		for(int i=0;i<sizeof(a);i++){
			b[i]=a[i]-48;
		}
		int num=0;
		for(int i=0;i<sizeof(b);i++){
			if(b[i]<9){
				c[num]=b[i];
				num++;
			}
		}
		for(int i=0;i<sizeof(num);i++){
			int maxx=c[0];
			for(int i=1;i<sizeof(a);i++){
				if(maxx<c[i]){
					maxx=c[i];
					c[i]==0;
					cout<<maxx;	
				}
			}
		}
	}
	
} 
