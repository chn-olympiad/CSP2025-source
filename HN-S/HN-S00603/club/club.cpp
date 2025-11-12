#include<bits/stdc++.h>
using namespace std;
long long n,a[5][100005],b[5],sum1[100005],sum2[100005],sum3[100005],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int o=0,p=0,q=0;
		memset(b,0,sizeof(b));
		memset(sum1,0,sizeof(sum1));
		memset(sum2,0,sizeof(sum2));
		memset(sum3,0,sizeof(sum3));
		cin>>n;
		for(int j=1;j<=n;j++)
			for(int i=1;i<=3;i++)
		    	cin>>a[i][j];
		for(int j=1;j<=n;++j){
		    int x=max(a[1][j],max(a[2][j],a[3][j]));
		    for(int i=1;i<=3;i++)
		    	if(x==a[i][j])
			        if(b[i]+1>n/2){
						if(i==1)
			                if(x>sum1[1]){
			                	sum1[++o]=x;
			                	sum1[1]=2e6;
			                	sort(sum1+1,sum1+o+1);
					    	}
					    	else{
					    		int y=max(a[2][j-1],a[3][j-1]);
					    		if(y+x>sum1[1]){
					    			if(y==a[2][j-1])sum2[++p]=y;
					    		    else sum3[++q]=y;
					    			sum1[++o]=x;
			                	    sum1[1]=2e6;
			                     	sort(sum1+1,sum1+o+1);
								}else{
					    			int g=max(a[2][j],a[3][j]);
					    			if(g==a[2][j])sum2[++p]=g;
					    		    else sum3[++q]=g;
								}
					    	}
					    if(i==2)
			                if(x>sum2[1]){
			                	sum2[++p]=x;
			                	sum2[1]=2e6;
			                	sort(sum2+1,sum2+p+1);
					    	}
					    	else{
					    		int y=max(a[1][j-1],a[3][j-1]);
					    		if(y+x>sum2[1]){
					    			if(y==a[1][j-1])sum1[++o]=y;
					    		    else sum3[++q]=y;
					    			sum2[++o]=x;
			                	    sum2[1]=2e6;
			                     	sort(sum2+1,sum2+p+1);
								}else{
					    			int g=max(a[1][j],a[3][j]);
					    		    if(g==a[1][j])sum1[++o]=g;
					    		    else sum3[++q]=y;
								}
					    	}
					    if(i==3)
			                if(x>sum3[1]){
			                	sum3[++q]=x;
			                	sum3[1]=2e6;
			                	sort(sum3+1,sum3+q+1);
					    	}
					    	else{
					    		int y=max(a[2][j-1],a[1][j-1]);
					    		if(y+x>sum3[1]){
					    			if(y==a[2][j-1])sum2[++p]=y;
					    		    else sum1[++o]=y;
					    			sum3[++q]=x;
			                	    sum3[1]=2e6;
			                     	sort(sum3+1,sum3+q+1);
								}else{
									int g=max(a[2][j],a[1][j]);
					    	    	if(g==a[2][j])sum2[++p]=g;
					    	    	else sum1[++o]=g;
								}
					    	}
					}
			        else{
			        	if(i==1){
			        		sum1[++o]=x;
			         	    sort(sum1+1,sum1+o+1);
			         	    b[1]++;
						}
			        	else if(i==2){
			        		sum2[++p]=x;
			         	    sort(sum2+1,sum2+p+1);
			         	    b[2]++;
						}
						else if(i==3){
			        		sum3[++q]=x;
			         	    sort(sum3+1,sum3+q+1);
			         	    b[3]++;
						}    
					}
		}
		ans=0;
		for(int i=0;i<=n;i++){
			if(sum1[i]<2e6)
			    ans+=sum1[i];
			if(sum2[i]<2e6)
			    ans+=sum2[i];
			if(sum3[i]<2e6)
			    ans+=sum3[i];
		}
		cout<<ans<<endl;
	}
	return 0;
} 

