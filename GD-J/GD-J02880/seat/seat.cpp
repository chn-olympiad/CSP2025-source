#include<bits/stdc++.h> 
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","in",cin);
	freopen("seat.out","out",cout);
   vector<int> a;
   int n,m,ans=0;
   cin>>n>>m;
   for(int i=1;i<=n;i++)
   {
   	 for(int j=1;j<=m;j++){
   	 	      int y;cin>>y;a.push_back(y);
   	 	      if(i==1&&j==1){ans=y;
				  }
		}
   }
   sort(a.begin(),a.end(),cmp);  int wei[21];
   for(int i=1;i<=n;i++)
   {
   	   wei[i]=i;
   }int j=1;
   for(int i=n;i>=1;i--)
   {
   	   wei[n+j]=i;j++;
   }
   int i=0; 
   while(ans!=a[i]){
   	  i++;
   }i++;//Ëù´¦Î»ÖÃĞòºÅ 
    int bei=i/(2*n);
    int yu=i%(2*n);
    if(yu==0){
    	cout<<bei*2<<" "<<1; 
	}else{
		 if(yu<=n){cout<<bei*2+1<<" "<<wei[yu];
		 }else{
		 	cout<<bei*2+2<<" "<<wei[yu];
		 }
	}
	return 0;
}
