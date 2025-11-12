#include<bits/stdc++.h> 
using namespace std;  

   int n,k,ans=0;
void solve(int l,int r,vector<int> num1)
{
	vector<int> xo;
	for(int i=l;i<=r;i++){
		xo.push_back(num1[i]);
	}
	if(xo.size()==1&&xo[0]!=k){return;
	}
	int le=0;
	for(int i=2;i<=xo.size();i++){
		  for(int j=le;j<xo.size()-i+1;j++){
		  	int xof=xo[j];
		  	    for(int q=1;q<i;q++){
		  	    	   xof=xof^xo[j+q];
				  }
				  if(xof==k){
				  	 ans++;
				  	 solve(le,j-1,xo);
				  	 le=j+i;
				  }
		  }
	}
	return ;
}
int main()
{ 
freopen(" xor.in","in",cin);
	freopen(" xor.out","out",cout);
   cin>>n>>k;vector<int> num(n+1),ke; ke.push_back(0);
   for(int i=0;i<n;i++)
   {
   	  cin>>num[i];
   	  if(num[i]==k){ke.push_back(i);ans++;
		 }
   }
   ke.push_back(n-1);
   for(int i=0;i<ke.size()-1;i++)
   {
   	  int l=ke[i],r=ke[i+1];
   	  if(l==r){continue;
		 }
		if(i==0&&num[l]!=k){
			solve(l,r-1,num);
		}
		if(r==n-1&&num[r]!=k){
			solve(l+1,r,num);
		}
		 solve(l+1,r-1,num);
   }
   cout<<ans;
	return 0;
}
