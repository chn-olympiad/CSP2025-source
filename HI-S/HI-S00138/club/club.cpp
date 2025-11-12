#include<bits/stdc++.h>
using namespace std;
const int MAXN=1001000;
struct stu{
	int x1,x2,x3;
	int maxx,num,two,num2;
}a[MAXN];

int n,t,vis[100100]; 
bool cmp(stu x,stu y){
	if(x.x1>y.x1) return true;
	return false;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
    	int xx=0,yy=0;
    	int x=0,y=0,z=0;
    	int wwx=0;
    	scanf("%d",&n);
    	for(int i=1;i<=n;i++){
    		scanf("%d%d%d",&a[i].x1,&a[i].x2,&a[i].x3);
    		if(a[i].x2==0) xx++;
    		if(a[i].x3==0) yy++;
    		a[i].maxx=max(a[i].x1,max(a[i].x2,a[i].x3));
    		if(a[i].maxx==a[i].x1){
    			a[i].num=1;
    			a[i].two=max(a[i].x2,a[i].x3);
    			if(a[i].two==a[i].x2) a[i].num2=2;
    			if(a[i].two==a[i].x3) a[i].num2=3;
    			continue;
			}
    		if(a[i].maxx==a[i].x2){
    			a[i].num=2;
    			a[i].two=max(a[i].x1,a[i].x3);
    			if(a[i].two==a[i].x1) a[i].num2=1;
    			if(a[i].two==a[i].x3) a[i].num2=3;
    			continue;
			}
    		if(a[i].maxx==a[i].x3){
    			a[i].num=3;
    			a[i].two=max(a[i].x2,a[i].x1);
    			if(a[i].two==a[i].x2) a[i].num2=2;
    			if(a[i].two==a[i].x1) a[i].num2=1;
    			
			}
    	//	cout<<a[i].maxx<<" "<<a[i].num<<" "<<a[i].two<<" "<<a[i].num2;
    	//	cout<<endl;
		}
		if(n==2){
			int x1=a[1].x1+a[2].x2;
			int x2=a[1].x1+a[2].x3;
			int x3=a[1].x2+a[2].x1;
			int x4=a[1].x2+a[2].x3;
			int x5=a[1].x3+a[2].x1;
			int x6=a[1].x3+a[2].x2;
			wwx=max(x6,max(x5,max(x4,max(x3,max(x2,x1)))));
			cout<<wwx<<endl;
	}
	else{
			if(xx==n&&yy==n){
				sort(a+1,a+1+n,cmp);
				int mid=n/2;
				for(int i=1;i<=mid;i++){
					wwx+=a[i].x1;
				}
				cout<<wwx<<endl;
			}else{
						
				   sort(a+1,a+1+n,cmp);
				   for(int i=1;i<=n;i++){
				   	if(x<n/2){
				    	if(a[i].x1==a[i].maxx){
				    	wwx+=a[i].maxx;
				    
				   		vis[i]=1;
				   		x++;
							}
						}else{
							if(a[i].x3>a[i].x2){
								wwx+=a[i].x3;
							
								z++;
							}else{
								wwx+=a[i].x2;
						
							y++;	
							}
						
						}				    	
					}
					cout<<wwx<<endl;
		
			
			}
			
		}
	}
	return 0;
}
