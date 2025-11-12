#include <bits/stdc++.h>
using namespace std;
struct node{
    int s;
    int bd;
    int cd;
}a[100000];
int n;
int cnt;
int op1=0;
int op2=0;
int op3=0;
int cou=1;
int yuo[1000000];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    
    cin>>cnt;
    for(int op=1;op<=cnt;op++){
       cin>>n;
       
	   for(int j=1;j<=n;j++){
          cin>>a[j].s>>a[j].bd>>a[j].cd;
       }
       op1=0;
       op2=0;
       op3=0;	
       for(int i=1;i<=n;i++){
    	  if(a[i].s>=a[i].bd&&a[i].s>=a[i].cd&&a[i].bd>=a[i].cd){//a>b>c
    		if(op1+1<=n/2){
    			op1+=1;
    			yuo[cou]+=a[i].s;
			}
			else if(op2+1<=n/2){
				op2+=1;
				yuo[cou]+=a[i].bd;
			}
			else{
				if(op3+1<=n/2){
    			op3+=1;
    			yuo[cou]+=a[i].cd;
			    }
			}
		  }
		  else if(a[i].s>=a[i].bd&&a[i].s>=a[i].cd&&a[i].cd>=a[i].bd){//a>c>b
			  if(op1+1<=n/2){
    			op1+=1;
    			yuo[cou]+=a[i].s;
			  }
			  else if(op3+1<=n/2){
				op3+=1;
				yuo[cou]+=a[i].cd;
			  }
			  else{
				 if(op2+1<=n/2){
    			   op2+=1;
    			   yuo[cou]+=a[i].bd;
			     }
			  }
		  }
		  else if(a[i].bd>=a[i].s&&a[i].bd>=a[i].cd&&a[i].s>=a[i].cd){//b>a>c
			  if(op2+1<=n/2){
    			op2+=1;
    			yuo[cou]+=a[i].bd;
			  }
			  else if(op1+1<=n/2){
				op1+=1;
				yuo[cou]+=a[i].s;
			  }
			  else{
				 if(op3+1<=n/2){
    			   op3+=1;
    			   yuo[cou]+=a[i].cd;
			     }
			  }
		  }
		  else if(a[i].bd>=a[i].s&&a[i].bd>=a[i].cd&&a[i].cd>=a[i].s){//b>c>a
			  if(op2+1<=n/2){
    			op2+=1;
    			yuo[cou]+=a[i].bd;
			  }
			  else if(op3+1<=n/2){
				op3+=1;
				yuo[cou]+=a[i].cd;
			  }
			  else{
				 if(op1+1<=n/2){
    			   op1+=1;
    			   yuo[cou]+=a[i].s;
			     }
			  }
		  }
		  
		  else if(a[i].cd>=a[i].s&&a[i].cd>=a[i].bd&&a[i].s>=a[i].bd){//c>a>b
			  if(op3+1<=n/2){
    			op3+=1;
    			yuo[cou]+=a[i].cd;
			  }
			  else if(op1+1<=n/2){
				op1+=1;
				yuo[cou]+=a[i].s;
			  }
			  else{
				 if(op2+1<=n/2){
    			   op2+=1;
    			   yuo[cou]+=a[i].bd;
			     }
			  }
		  }
		  else if(a[i].cd>=a[i].s&&a[i].cd>=a[i].bd&&a[i].bd>=a[i].s){//c>b>a
			  if(op3+1<=n/2){
    			op3+=1;
    			yuo[cou]+=a[i].cd;
			  }
			  else if(op2+1<=n/2){
				op2+=1;
				yuo[cou]+=a[i].bd;
			  }
			  else{
				 if(op1+1<=n/2){
    			   op1+=1;
    			   yuo[cou]+=a[i].s;
			     }
			  }
		  }
	   }
	   cou+=1;
	}
	for(int i=1;i<=cnt;i++){
	   cout<<yuo[i]<<endl;	
	}
    /*while(oio>0){
    	
    	int jl;
    	int jl2;
    	int jl3;
    	for(int i=1;i<=n;i++){
    		if(a[i].s==a1[i].yu){
    		    jl=i;
			}
			if(a[i].bd==b1[i].yue){
				jl2=i;
			}
			if(a[i].cd==c1[i].yuue){
				jl3=i;
			}
		}
		if(jl<jl2&&jl<jl3){
			if(op1+1<=n/2){
				op1+=1;
				yuo[cou]+=a1[jl].yu;
				oio-=1;
			}
			else if(jl>jl2&&jl<jl3){
				if(op2+1<=n/2){
					op2+=1;
					yuo[cou]+=b1[jl2].yue;
					oio-=1;
				}
			}
			else{
				if(op3+1<=n/2){
					op3+=1;
					yuo[cou]+=c1[jl3].yuue;
					oio-=1;
				}
			}
		}
    	
	}
    cout<<yuo[1];
    */
    
    return 0;
}
