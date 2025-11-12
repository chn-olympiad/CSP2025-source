#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct abc{
	string x;
	int num;
	
};
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    abc *a=new abc[n];
    cin>>n>>k;
    for(int i=0;i<n;i++){
    	cin>>a[i].num; 
    	int tmp=a[i].num;
    	while(tmp>0){
    		if(tmp%2==0){
    			a[i].x+='0';
			}
			else{
				a[i].x+='1';
			}
    		tmp=(tmp-tmp%2)/2;
		}
	}
    return 0;
}