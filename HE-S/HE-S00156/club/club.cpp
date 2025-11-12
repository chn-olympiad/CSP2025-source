#include<bits/stdc++.h>
using namespace std;
long int n,t,maxx[200010],a[200010][5],f[200020],cnt[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
	
		for(long int i=1;i<=n;i++){		 
			for(long int j=1;j<=3;j++){
				scanf("%ld",&a[i][j]);
			}
		}
		
		if(n==1){
			long int maxxx=-1;
			for(long int i=1;i<=3;i++){
				maxxx=max(maxxx,a[1][i]);	
			}
			cout<<maxxx;
			continue;
		}
		if(n==2){
			long int max1=-1;
			for(long int i=1;i<=3;i++){
				max1=max(max1,a[1][i]);		
			}
			long int max2=-1;
			for(long int i=1;i<=3;i++){
				max2=max(max2,a[2][i]);		
			}
			cout<<max1+max2;
			continue;
		}
		else{
			long int minn=1e5;
			for(long int i=1;i<=n;i++){
				maxx[i]=max(a[i][1],max(a[i][2],a[i][3]));	//第i个人对三个社团的最大满意度 
				minn=min(maxx[i],minn);					//前i个人满意度最大的最小值 
				int minnn;								//记录前i个人最大满意度的最小值出自第minnn个人 
				for(long int j=1;j<=i;j++){					
					if(maxx[j]==minn) minnn=j;
				}	
					
				for(long int j=1;j<=3;j++){
					if(maxx[i]==a[i][j]){
						cnt[j]++;						//记录第i个人选择了第j个社团 计数器++ 
						f[i]=f[i-1]+maxx[i];				//f[i]：满意度总和+=第i个人的选择的社团的满意度 
					}
					if(cnt[j]>n/2){			//社团人数超过总人数一半 将二者其一其调配到第二满意的社团，使利益最大化 
						f[i]-=minn;
						cnt[j]--;
						
						long int m=a[i][j];
						a[i][j]=0; 
						maxx[i]=max(a[i][1],max(a[i][2],a[i][3]));
						long int zuida=-1;
						for(long int k=1;k<=3;k++){
							zuida=max(zuida,a[i][k]); 		//zuida为第i个人第二选择 
						}
						
						long int q=a[minnn][j];
						a[minnn][j]=0;
						long int zuida2=-1;					//第minnn个人的第二选择zuida2 
						zuida2=max(a[minnn][3],max(a[minnn][1],a[minnn][2]));
						if(maxx[minnn]+zuida>=maxx[i]+zuida2)	//保留先前 使第i个人取第二志愿 
						{
							f[i]=f[i-1]+zuida;
							for(long int k=1;k<=3;k++){
							if(zuida==a[i][k]){
								cnt[k]++;
							}
						}
						}
						else{
							f[i]=f[i-1]+zuida2+maxx[i]-maxx[minnn];
						}
						
					}
				}
			}
			printf("%d",f[n]);
		}	
	}
		
	


	return 0;
}
