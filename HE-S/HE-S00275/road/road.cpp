#include<bits/stdc++.h>
using namespace std;
struct er{
	int a1;
	int b;
};
er a[100000][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int g=0;g<t;g++){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				//cin>>a[i][j].a1;
				scanf("%d",&a[i][j].a1);
				a[i][j].b=j;
			}
		}
		int m[3][n];
		for(int i=0;i<3;i++){
			for(int j=0;j<n;j++){
				m[i][j]=-1;
			}
		}
		for(int i=0;i<n;i++){
			for(int k=0;k<2;k++){
				for(int j=0;j<2;j++){
					if(a[i][j].a1<a[i][j+1].a1){
						swap(a[i][j].a1,a[i][j+1].a1);
						swap(a[i][j].b,a[i][j+1].b);
					} 
				}
			}
		}
		int l[3]={0,0,0};
		for(int i=0;i<n;i++){
			m[a[i][0].b][i]=i;
			l[a[i][0].b]++;
		}
		for(int i=0;i<3;i++){
			for(int k=0;k<n-1;k++){
				for(int j=0;j<n-1;j++){
					if(a[m[i][j]][0].a1<a[m[i][j+1]][0].a1){
						swap(m[i][j],m[i][j+1]);
					}
				}
			}
		}
		int r=0,s,bj;
		bool f=1;
		while(f&&r<3){
			if(l[r]>n/2){
				f=0;
				s=l[r]-n/2;
				bj=r;
			}
			r++;
		}
						ans+=a[m[i][j]][1].a1;
					}else{
						ans+=a[m[i][j]][0].a1;
					}
				}
			}
			printf("%d\n",ans);
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
