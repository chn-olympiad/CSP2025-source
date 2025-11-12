#include<bits/stdc++.h>
using namespace std;
int t,n,a1[100010],a2[100010],a3[100010],maxx,d1,d2,d3;
bool a,b;
bool pba(){
	for(int i=1;i<=n;i++){
		if(a2[i]!=0 || a3[i]!=0){
			return 0;
		}
	}
	return 1;
}
bool pbb(){
	for(int i=1;i<=n;i++){
		if(a3[i]!=0){
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);		
		}
		if(pba()){
			sort(a1+1,a1+n+1);
			for(int i=n;i>n/2;i--){
				maxx+=a1[i];
			}
		}else if(pbb()){
			for(int i=1;i<=n;i++){
				if(a1[i]<a2[i]&&d2<n/2){
					maxx+=a2[i];
					d2++;
					continue;
				}else if(a2[i]<a1[i]&&d1<n/2){
					maxx+=a1[i];
					d1++;
					continue;
				}else{
					if(d1>d2){
						maxx+=a2[i];
						d2++;
						continue;
					}else{
						maxx+=a1[i];
						d1++;
						continue;
					}
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(a1[i]>a2[i]&&a1[i]>a3[i]){
				if(d1<n/2){
					d1++;
					maxx+=a1[i];
					continue;
				}else{
					if(a2[i]>a3[i]&&d2<n/2){
						d2++;
						maxx+=a2[i];
						continue;
					}else if(a2[i]<a3[i]&&d3<n/2){
						d3++;
						maxx+=a3[i];
						continue;
					}else{
						if(d2>d3){
							d3++;
							maxx+=a3[i];
							continue;
						}else{
							d2++;
							maxx+=a2[i];
							continue;
						}
					}
				}
			}
			if(a2[i]>a1[i]&&a2[i]>a3[i]){
				if(d2<n/2){
					d2++;
					maxx+=a2[i];
					continue;
				}else{
					if(a1[i]>a3[i]&&d1<n/2){
						d1++;
						maxx+=a1[i];
						continue;
					}else if(a1[i]<a3[i]&&d3<n/2){
						d3++;
						maxx+=a3[i];
						continue;
					}else{
						if(d1>d3){
							d3++;
							maxx+=a3[i];
							continue;
						}else{
							d1++;
							maxx+=a1[i];
							continue;
						}
					}
				}
			}
			if(a3[i]>a2[i]&&a3[i]>a1[i]){
				if(d3<n/2){
					d3++;
					maxx+=a3[i];
					continue;
				}else{
					if(a1[i]>a2[i]&&d1<n/2){
						d1++;
						maxx+=a1[i];
						continue;
					}else if(a1[i]<a2[i]&&d2<n/2){
						d2++;
						maxx+=a2[i];
						continue;
					}else{
						if(d1>d2){
							d2++;
							maxx+=a2[i];
							continue;
						}else{
							d1++;
							maxx+=a1[i];
							continue;
						}
					}
				}
			}
			}
		}
		printf("%d",maxx);
		maxx=0,d1=0,d2=0,d3=0;
	}
	return 0;
}
