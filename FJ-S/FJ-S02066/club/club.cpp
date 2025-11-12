#include<bits/stdc++.h> 
using namespace std;
int es(int n,int a,int b,int c){
	if(a>n/2){
		return 1;
	}
	if(b>n/2){
		return 2;
	}
	if(c>n/2){
		return 3;
	}
	return 0;
}
int main(){
	define("club.in");
	int t;
	cin>>t;
	int re[10005]={0};
	for(int z=0;z<t;z++){
	    int n;
	    cin>>n;
	    int a[4][10005]={0};
	    priority_queue<int> b;
	    priority_queue<int> c;
	    priority_queue<int> d;
	    int b1=0,c1=0,d1=0;
	    for(int i=0;i<n;i++){
	    	cin>>a[1][i]>>a[2][i]>>a[3][i];
	    	if(a[1][i]>a[2][i]&&a[1][i]>a[3][i]){
	    		if(a[2][i]>a[3][i]){
	    			b.push(a[1][i]-a[2][i]);
				}else{
					b.push(a[1][i]-a[2][i]);
				}
				b1++;
				re[z]+=a[1][i]; 
			}else if(a[2][i]>a[1][i]&&a[2][i]>a[3][i]){
				if(a[1][i]>a[3][i]){
	    			c.push(a[2][i]-a[1][i]);
				}else{
					c.push(a[2][i]-a[3][i]);
				}
				c1++;
				re[z]+=a[2][i];
			}else{
				if(a[1][i]>a[2][i]){
	    			d.push(a[3][i]-a[1][i]);
				}else{
					d.push(a[3][i]-a[2][i]);
				}
				d1++;
				re[z]+=a[3][i];
			}
		}
		int h=es(n,b1,c1,d1);
		if(h==1){
			for(int i=0;i<(n/2);i++){
		       	b.pop();
		    }
		    for(int i=0;i<b1-(n/2);i++){
				re[z]-=b.top();
				b.pop();
	    	}
	    	d1=n/2;	
		}else if(h==2){
			for(int i=0;i<(n/2);i++){
		       	c.pop();
		    }
		    for(int i=0;i<c1-(n/2);i++){
				re[z]-=c.top();
				c.pop();
	    	}
	    	c1=n/2;
		}else if(h==3){
			for(int i=0;i<(n/2);i++){
		       	d.pop();
		    }
		    for(int i=0;i<d1-(n/2);i++){
				re[z]-=d.top();
				d.pop();
	    	}
	    	d1=n/2;
		}
	}
	for(int i=0;i<t;i++){
		cout<<re[i]<<endl;
	}
	define("club.out");
	return 0;
}
