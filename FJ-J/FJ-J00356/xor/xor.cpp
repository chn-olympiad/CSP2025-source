#include<bits/stdc++.h>
using namespace std;
int a,b=0,k;
int c[1145141];
int main(){
	freopen("xor4.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>k;
	if(k==1){
		for(int i=0;i<a;i++){
			cin>>c[i];
			if(c[i]==1)b++;
		}
		cout<<b;
	}
	else{
		for(int i=0;i<a;i++){
			cin>>c[i];
			
		}for(int i=0;i<a;i++){
			if(c[i]==0)b++;
			if(c[i]==1&&c[i+1]==1){
				c[i+1]=2;
				b++;
			}
		}
		cout<<b;
	}
	return 0;
}
