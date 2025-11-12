#include<bits/stdc++.h>
using namespace std;
struct er{
	int a1;
	int b;
};
er a[100000][3];
int main(){
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

	return 0;
}
