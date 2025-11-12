#include <bits/stdc++.h>
using namespace std;
int n,t;
struct eg{
	int x,g,c;
}a[100005][3];


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=0;k < t;k++){
		cin>>n;
		int sum=0;
		int e=n/2;
		int maxn=0,c1[3]={0};
		for(int i=0;i < n;i++){
			int max1=-1;
			for(int j=0;j < 3;j++){
				cin>>a[i][j].x;a[i][j].g=0;a[i][j].c=j;
				if(a[i][j].x >max1)max1=a[i][j].x,maxn=j;
			}		
			c1[maxn]++;
			a[i][maxn].g=1;
			sum+=max1;
			if(c1[maxn] > e){
				int min1=a[i][maxn].x,minn=i;
				for(int j=i-1;j >= 0;j--){\
					
					if(a[j][maxn].x < min1&&a[j][maxn].g==1){
						min1=a[j][maxn].x,minn=j;
					}else if(a[j][maxn].x > min1&&a[j][maxn].g==1){
						int max3=-1,max3n=0;
						for(int o=0;o < 3;o++){
							if(c1[o] < e&&o!=maxn){
								if(max3 < a[j][o].x+min1){
									max3=a[j][o].x+min1;max3n=o;
								}
							}
						}
						
						if(a[j][maxn].x < max3){
							a[j][max3n].g=1;sum=sum-a[j][maxn].x+max3;c1[max3n]++;
						}
					}
				}
				sum-=min1;a[minn][maxn].g=2;c1[maxn]--;a[minn][maxn].x=-2;int max2=-1,max2n=0;
				
				for(int j=0;j < 3;j++){
					if(max2 < a[minn][j].x)max2=a[minn][j].x,max2n=j;
				}
				sum+=max2;a[minn][max2n].g=1;c1[max2n]++;
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
} 
