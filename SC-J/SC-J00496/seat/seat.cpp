#include <bits/stdc++.h>
using namespace std;
int nums[110];
bool cmp(int &x,int &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	bool f=false;
	int x=1,y=1;
	int n,m;
	int R_s;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>nums[i];
		if(i==0) R_s=nums[i];
	}
	sort(nums,nums+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(R_s!=nums[i]){
			if(y==1&&f){
	        	x++;
	        	f=false;
     		}
	  	    else if(y==m&&!f){
	  	  		x++;
	  	  		f=true;
	  	    }else{
	  	    	if(!f) y++;
	    	    else y--;
			}
		}else{
			cout<<x<<' '<<y;
			return 0;
		}
	}
	return 0;
}