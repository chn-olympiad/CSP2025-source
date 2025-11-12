//GZ-S00083 岑巩县第一中学 吴先杰
#include <bits/stdc++.h>
int a[100001][4];
int b[4];
int tans[6];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,total=0,max=0;
	int k=0,temp;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			for(int j1=1;j1<=3;j1++){
				scanf("%d",&a[j][j1]);
			}
		}
		for(int s=1;s<=3;s++){
			for(int s1=1;s1<=n;s1++){
	    		if(a[s1][s]!=0){
		        	b[s]++;
				}
			}
		}
		
		if(b[1]==b[2] && b[1]==b[3]){
			for(int ran=1;ran<=3;ran++){
				max=0;
	    		for(int j=1;j<=n;j++){
	    		    if(max==n/2){max=0;break;}
    				for(int x=1;x<=n;x++){
					    if(a[j][ran]>=a[x][ran] && j!=x && a[j][0]==0){
					    	k++;
					       	if(k>=n/2){
					       		total=total+a[j][ran];
					       		k=0;
					       		a[j][0]=1;
					       		max++;
				    	    	break;
				    	    }
			    		}
		    		}
	    		}
    		}
    		tans[t]=total;
    		total=0;
    		k=0;
    		
	    }else{
    		if(b[3]==0 && tans[t]!=0){
    		    for(int ran=1;ran<=2;ran++){
    			    max=0;
    	            for(int j=1;j<=n;j++){
    	   	        	if(max==n/2){max=0;break;}
        		            for(int x=1;x<=n;x++){
    				        if(a[j][ran]>=a[x][ran] && j!=x && a[j][0]==0){
       					        k++;
    					        if(k>=n/2){
    				   	            total=total+a[j][ran];
    				        	    k=0;
    				             	a[j][0]=1;
    				               	max++;
    			    	            break;
    				    	    }
    			            }
    		            }
    	            }
                }
	       	    tans[t]=total;
        	    total=0;
    	    
	    	}else{
	    	    if(b[3]==0 && b[2]==0 && tans[t]!=0){
	    		max=0;
	        	for(int j=1;j<=n;j++){
        		    for(int x=1;x<=n;x++){
	    				if(a[j][1]>=a[x][1] && j!=x && a[j][0]==0){
	    				    k++;
	    				    if(k>=n/2){
	    				       	total=total+a[j][1];
		    			       	k=0;
		    			        a[j][0]=1;
		    		    	    break;
	    			    	}
	    		        }
	    	        }
	    	    }
	    	    tans[t]=total;
        	    total=0;
        	    k=0;

        	    }else{
        	    	break;
				}
     		}
	    }
	}
	for(int g=1;g<=t;g++){
		if(g==t){
			printf("%d",tans[g]);
		}else{
			printf("%d\n",tans[g]);
		}
	}
	return 0;
}
