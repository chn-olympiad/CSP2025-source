#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c,d[100100][3],e[100100][3],a1[100100]={200100};
int b1[100100]={200100},c1[100100]={200100},ans[5],k;
int cmp(int x,int y){
	if(x>y) return true;
	else return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++){
		for(int i=1;i<=n;i++){
			d[i][1]=0;
			d[i][2]=0;
			e[i][1]=0;
			e[i][2]=0;
		}
		a=0;b=0;c=0;k=0;ans[1]=0;ans[2]=0;ans[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			if(x>=y&&x>=z){
				d[i][1]=x;
				a+=1;
				e[i][1]=1;
				if(y>=z){
					d[i][2]=y;
					e[i][2]=2;
				}
				else{
				    d[i][2]=z;
					e[i][2]=3;
				}
			}
			else if(y>x&&y>=z){
				d[i][1]=y;
				e[i][1]=2;
				b+=1;
				if(x>=z){
					d[i][2]=x;
					e[i][2]=1;
				}
				else{
				    d[i][2]=z;
					e[i][2]=3;
				}
			}
			else{
				d[i][1]=z;
				e[i][1]=3;
				c+=1;
				if(x>=y){
					d[i][2]=x;
					e[i][2]=1;
				}
				else{
				    d[i][2]=y;
					e[i][2]=2;
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<d[i][1]<<" "<<d[i][2]<<" "<<e[i][1]<<" "<<e[i][2]<<endl;
//		}
     for(int i=1;i<=n;i++){
			a1[i]=200100;
			b1[i]=200100;
			c1[i]=200100;
		}
//        for(int i=1;i<=n;i++){
//			cout<<a1[i]<<" "<<b1[i]<<" "<<c1[i]<<endl;
//		}
		for(int i=1;i<=n;i++){
			if(e[i][1]==1){
				ans[1]+=d[i][1];
				a1[i]=d[i][1]-d[i][2];
			}
			if(e[i][1]==2){
			ans[2]+=d[i][1];
				b1[i]=d[i][1]-d[i][2];
			}
			if(e[i][1]==3){
			   ans[3]+=d[i][1];        
				c1[i]=d[i][1]-d[i][2];
			}
		}
//		cout<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<endl;
//        for(int i=1;i<=n;i++){
//			cout<<a1[i]<<" "<<b1[i]<<" "<<c1[i]<<endl;
//		}
		if(a>n/2){               
		for(int i=1;i<=a-n/2;i++){
		int sum=200100;
			for(int l=1;l<=n;l++){
		        if(a1[l]<=sum){
		        	sum=a1[l];
		        	k=l;
				}
			}
//			cout<<sum<<endl;
			a1[k]=200100;
			ans[e[k][1]]-=d[k][1];
			ans[e[k][2]]+=d[k][2];
	    }
	    }
	    else if(b>n/2){               
		for(int i=1;i<=b-n/2;i++){
		int sum=200100;
			for(int l=1;l<=n;l++){
		        if(b1[l]<=sum){
		        	sum=b1[l];
		        	k=l;
				}
			}
//			cout<<sum<<endl;
			b1[k]=200100;
			ans[e[k][1]]-=d[k][1];
			ans[e[k][2]]+=d[k][2];
	    }
	    }
	    else if(c>n/2){               
		for(int i=1;i<=c-n/2;i++){
		int sum=200100;
			for(int l=1;l<=n;l++){
		        if(c1[l]<=sum){
		        	sum=c1[l];
		        	k=l;
				}
			}
//			cout<<sum<<endl;
			c1[k]=200100;
			ans[e[k][1]]-=d[k][1];
			ans[e[k][2]]+=d[k][2];
	    }
	    }
	    cout<<ans[1]+ans[2]+ans[3]<<endl;
	}
	return 0;
}
