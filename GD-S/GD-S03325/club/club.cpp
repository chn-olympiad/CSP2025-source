#include <bits/stdc++.h>
using namespace std;
struct node{
	int club[3];
	int max=0,maxc=0,max2=0;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,sum=0;
		cin>>n;
		node a[n+1]={0};
		for(int i=1; i<=n; i++){
			for(int j=0; j<3; j++){
		    	cin>>a[i].club[j];
		    	if(a[i].club[j]>a[i].max){
		    		a[i].max=a[i].club[j];
		    		a[i].maxc=j;
				}
			}
			for(int j=0; j<3; j++){
				if(j==a[i].maxc) continue;
				if(a[i].club[j]>=a[i].max2){
					a[i].max2=a[i].club[j];
				}
			}
		}
		int b[3]={0},bd=-1,dd=0;
		for(int i=1; i<=n; i++){
			b[a[i].maxc]++;
			if(b[a[i].maxc]>(n/2)){
				bd=a[i].maxc;
				dd=i;
				break;
			}
			sum+=a[i].max;
		}
		if(bd==-1) cout<<sum<<endl;
		else {
			int xmin=20001,mindz=-1;
			for(int i=dd; i<=n; i++){
				if(a[i].maxc==bd){
					if(mindz==-1)
						for(int j=1; j<dd; j++)
			    			if((a[j].max-a[j].max2)<xmin){
			                    xmin=(a[j].max-a[j].max2);
			                    mindz=j;
    		        		}
					if((a[i].max-a[i].max2)>xmin){
						sum+=(a[i].max+a[mindz].max2);
					    sum-=a[mindz].max;
						node x=a[mindz];
			    	    a[mindz]=a[i];
			    	    a[i]=x;
			    	    mindz=-1;
			    	    xmin=20001;
					}
				    if(mindz!=-1) sum+=a[i].max2;
				}
			}	
		    cout<<sum<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
    // goobye
} 


