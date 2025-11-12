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
		if(f){
			int ans=0;
			for(int i=0;i<3;i++){
				for(int j=0;j<n;j++){
					if(m[i][j]!=-1){
						ans+=a[m[i][j]][0].a1;
					}
				}
			}
			printf("%d\n",ans);
		}else{
			int sw;
			//for(int j=n-1;j>=0;j--){
			//	for(int i=0;i<3;i++){
			//		if(i!=bj){
			//			if(m[i][j]!=-1){
			//				swap(m[bj][j],m[i][n-1]);
			//				cout<<1111<<endl;
			//			}
			//			cout<<"j"<<j<<endl;
			//		}
			//	}		
			//}
			for(int i=0;i<s;i++){
				for(int k=0;k<3;k++){
					if(k!=bj){
						for(int j=n-1;j>=0;j--){
							swap(m[bj][j],m[k][n-1]);
						}
					}
				}
			}
			for(int i=0;i<3;i++){
				for(int j=0;j<n;j++){
					cout<<m[i][j]<<" ";
				}
				cout<<endl;
			}
			int ans=0;
			//for(int i=0;i<3;i++){
			//	for(int j=0;j<n;j++){
			//		if(m[i][j]!=-1){
			//			ans+=a[m[i][j]][0].a1;
			//		}
			//	}
			//}
			for(int i=0;i<3;i++){
				for(int j=0;j<n;j++){
					if(i!=bj){
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
