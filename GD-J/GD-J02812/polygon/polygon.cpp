#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],m,cnt=0,num=0,maxxx=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		num+=a[i];
		maxxx=max(a[i],maxxx);
	}
	int sum=0,maxx=0,ans=num;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		maxx=a[i];
		if(a[i]!=maxxx){
			if((num-sum)>maxxx*2)
			{
				cnt++;
				sum=0;
			}
		}
		else{
			if((num-sum)>a[i]*2){
				cnt++;
				sum=0;
			}
		}
		for(int j=1;j<=n;j++){
		    sum+=a[j];
			maxx=max(a[j],maxx);
			if(j!=i){
				m=abs(j-i)+1;
				if((sum>maxx*2)&&(m>=3)){
					cnt++;
					sum=0;
					maxx=0;
					m=0;
				}
			}
			if(j!=i){
				ans-=sum;
				if((a[i]!=maxxx)&&a[j]!=maxxx){
					m=n-(abs(j-i)+1);
					if((sum>maxxx*2)&&(m>=3)){
						cnt++;
						sum=0;
						maxx=0;
						m=0;
						ans=0;
			    	}
				}
			}
		}
	}
	printf ("%d",cnt);
	return 0;
}
