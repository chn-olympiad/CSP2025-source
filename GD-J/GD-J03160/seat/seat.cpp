#include<bits/stdc++.h>
using namespace std;
int n,m, a[10005]; 
bool cmp(int x,int  y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	int r=a[1],rs=0;
	
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			rs=i;
		}
	}int tmp=rs/n;
	if((rs/n)%2==0&&(rs-(n*(rs/n)))!=0){
	    
		int lie=(rs/n)+1;
		int hang=rs-(n*(rs/n));
		printf("%d %d",lie,hang);
	}else  if((tmp%2)==1&&(rs-(n*tmp))==0){
			
			int lie=(rs/n);
			int hang=n;
			printf("%d %d",lie,hang);
    }else if((tmp%2)==1&&(rs-(n*tmp))!=0){
	
		int lie=tmp+1;
		int hang=n-(rs-(n*tmp)-1);
		printf("%d %d",lie,hang);
	}else if(tmp%2==0&&(rs-(n*tmp))==0){
	    	
	    	int lie=tmp;
	    	int hang=n;
	    	printf("%d %d",lie,hang);
	}
	
	return 0;
}
