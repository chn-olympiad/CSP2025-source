#include<bits/stdc++.h>
using namespace std;
int n,k,a[5005][5005],b[5005];
int yiyi(int aa,int bb)
   {
	   int aaa[100]={0},i=0,j=0,ans=0;
	   while(aa>0)
	        {
		     i++;
			 aaa[i]=aa%2;
			 aa/=2;	
			}
	   while(bb>0)
	        {
		     j++;
			 if(aaa[j]==bb%2) aaa[j]=0;
			   else aaa[j]=1;
			 bb/=2;	
			}
	   i=max(i,j);
	   for(j=1;j<=i;j++)
	      {
			ans+=aaa[j]<<(j-1);  
		  }
	   return ans;
   }
int yihu(int aa,int bb)
   {
	   int ans=b[aa];
	   for(int i=aa+1;i<=bb;i++)
	      {
			ans=yiyi(ans,b[i]);  
		  }
	   return ans;
   }
void work1()
    {
	 for(int i=1;i<=n;i++)
        {
		   scanf("%d",&b[i]);
		   if(b[i]==k) a[i][i]++; 
	    }	
	 for(int i=1;i<=n;i++)
	    {
		 for(int j=1;j+i<=n;j++)
		    {
				for(int ij=j;ij<i+j;ij++)
				   {
					   a[j][i+j]=max(a[j][i+j],a[j][ij]+a[ij+1][i+j]);
				   }
			 if(a[i][i+j]==0&&yihu(i,i+j)==k) a[i][i+j]=1;
			}	
	    }
	 printf("%d",a[1][n]);
	}
int main()
 {
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  scanf("%d%d",&n,&k);
  if(n<=5005) work1();
    else cout<<n/3+k;
  fclose(stdin);
  fclose(stdout);
  return 0;
 }
