#include<bits/stdc++.h>
using namespace std;
int q[100001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=a;i++){
    	cin>>q[i];
	}
	if(b==1){
		int sum=0;
		for(int i=1;i<=a;i++){
			if(q[i]==1){
				sum++;
			}
		}
		cout<<sum;
	}else{
		int sum=0;
		for(int i=1;i<=a;i++){
		    if(q[i]==0){
		    	sum++;
			}else if(q[i]==1&&q[i+1]==1){
				sum++;
				i++;
			}
	    }
	    cout<<sum;
	}
	
	return 0;
}

