#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char n[100001];
	int ans=0,k[100001],nd=1,m;
	cin.getline(n,100001);
	int l=strlen(n);
	for(int x=0;x<l;x++){
		int m=n[x]-48;
	    if(m>=0&&m<=9){
	     	k[nd]=n[x]-48;
	     	nd++;
		}	    
	}
    int ly=nd;
    for(int x=1;x<ly-1;x++){
    	for(int y=x+1;y<ly;y++){
    		if(k[y]>k[x]){
    			swap(k[y],k[x]);
			}
		}
	}
	for(int x=1;x<ly;x++){
		cout<<k[x];
	}
	return 0;
}
